/*********************************************************************************************

    __  ____                 __  __               __
   /  |/  (_)_____________  / / / /___ __________/ /
  / /|_/ / / ___/ ___/ __ \/ /_/ / __ `/ ___/ __  /
 / /  / / / /__/ /  / /_/ / __  / /_/ / /  / /_/ /
/_/  /_/_/\___/_/_  \____/_/ /_/\__,_/_/___\__,_/             __      __                _  __
        / ____/ (_)___ _/ /_  / /_   / ___/(_)___ ___  __  __/ /___ _/ /_____  _____   | |/ /
       / /_  / / / __ `/ __ \/ __/   \__ \/ / __ `__ \/ / / / / __ `/ __/ __ \/ ___/   |   /
      / __/ / / / /_/ / / / / /_    ___/ / / / / / / / /_/ / / /_/ / /_/ /_/ / /      /   |
     /_/   /_/_/\__, /_/ /_/\__/   /____/_/_/ /_/ /_/\__,_/_/\__,_/\__/\____/_/      /_/|_|
               /____/
*********************************************************************************************/

#include <fpga.h>
#include "../include/cglm/cglm.h"
#include <string.h>
#include <stdio.h>
#include "em_gpio.h"
#include "aircraft.h"
#include "ai_aircraft.h"
#include "ai_aircraft_init.h"
#include "controller.h"
#include "game.h"
#include "debug.h"
#include "display.h"
#include "transformation.h"

int iteration = 0;
Aircraft aircraft;              // The player's aircraft
Controller controller;          // The controller
AiAircraft *ai_aircraft;        // The "enemy" aircraft
MvpMatrixEntry *matrix_entries; // The MVP matrices for all aircraft
Sprite camera_queue[CAMERA_LAG];
int current_camera_index = 0;
int toggle_display_cooldown = 0;

/*********************************************************************************************
 * @brief Initializes the game state and all required components
 *
 * Sets up the game environment including hardware peripherals, player aircraft,
 * AI aircraft, and rendering matrices. Must be called before any other game functions.
 *
 * @return void
 *********************************************************************************************/
void game_init()
{
  // INIT PERIPHERAL DEVICES
  spi_init();                   // spi for FPGA communication
  display_init(&aircraft);      // i2c for writing to displays
  controller_init(&controller); // adc and buttons for capturing input

  // INIT STRUCTS
  aircraft_init(&aircraft);

  // GENERATE ENEMY AIRCRAFT
  ai_aircraft = (AiAircraft *)malloc(num_aircraft * sizeof(AiAircraft));
  ai_aircraft_copy(ai_aircraft, original_aircraft, num_aircraft);
  ai_aircraft_init(ai_aircraft, num_aircraft);

  // ALLOCATE MATRIX ENTRIES
  matrix_entries = (MvpMatrixEntry *)malloc((num_aircraft + 1) * sizeof(MvpMatrixEntry));

  // Initialize camera queue
  for (int i = 0; i < CAMERA_LAG; i++)
  {
    memset(&camera_queue[i], 0, sizeof(Sprite));
  }
}

/*********************************************************************************************
 * @brief Processes a single frame of active gameplay
 *
 * Handles all game logic for one frame including:
 * - Controller input processing
 * - Aircraft movement and physics
 * - Collision detection
 * - Weapon systems
 * - Camera positioning
 * - Display updates
 *
 * @param frame_counter Current frame number
 * @param game_active Pointer to game state flag. Set to 0 when game ends
 * @return void
 *********************************************************************************************/
void game_process_action(uint32_t frame_counter, uint32_t *game_active)
{
  controller_get_inputs(&controller, frame_counter);

  /// CHECK FOR HIT WHEN FIRING ///
  if (controller.fire)
  {
    controller_led_turn_on();
    if (toggle_display_cooldown < 0)
    {
      toggle_display_cooldown = 30;
      display_toggle_display();
    }
    controller.fire = 0;
    aircraft_check_hit(&aircraft, ai_aircraft, num_aircraft);
  }
  else
    controller_led_turn_off();
  toggle_display_cooldown--;

  /// CHECK FOR COLLISION ///
  aircraft_check_collision(&aircraft, ai_aircraft, num_aircraft);

  ai_aircraft_update_status(ai_aircraft, num_aircraft); // Update status or counter for ai aircraft

  aircraft_update_pose(&aircraft, &controller); // Update pose on player aircraft

  ai_aircraft_update_pose(ai_aircraft, num_aircraft, frame_counter); // Update pose of remaining ai aircraft

  /// CAMERA QUEUE LOGIC ///
  // Add current camera state to the queue
  current_camera_index = (current_camera_index + 1) % CAMERA_LAG;
  Sprite camera = {
      .x = aircraft.x,
      .y = aircraft.y,
      .z = aircraft.z,
      .roll = aircraft.roll,
      .pitch = aircraft.pitch,
      .yaw = aircraft.yaw,
  };
  camera_queue[current_camera_index] = camera;

  // Retrieve the lagged camera state
  int lagged_index = (current_camera_index + 1) % CAMERA_LAG;
  Sprite lagged_camera = camera_queue[lagged_index];

  /// GENERATE MATRICES FOR PLAYER AND AI AIRCRAFT ///
  matrix_entries[0].flag_id = 0x0; // 66 // 00000000
  generate_mvp_matrix((Sprite *)&aircraft, &lagged_camera, matrix_entries[0].mvp_matrix);

  uint8_t num_alive = 0;
  for (int i = 0; i < num_aircraft; i++)
  {
    uint8_t flag = ai_aircraft[i].status;
    if (flag == 2)
      continue;
    uint8_t id = ai_aircraft[i].id;
    matrix_entries[num_alive + 1].flag_id = flag | id;
    generate_mvp_matrix((Sprite *)&ai_aircraft[i], &lagged_camera, matrix_entries[num_alive + 1].mvp_matrix);
    num_alive++;
  }

  /// SEND NEW MATRICES TO FPGA ///
  fpga_frame_send(matrix_entries, num_alive + 1, frame_counter);

  /// UPDATE DISPLAY ///
  if (frame_counter % 30 == 0)
  {
    display_set_number();
    display_print_string();
  }
  /// TOGGLE DISPLAY NUMBER ///
  if (frame_counter % 180 == 0)
  {
    //    display_toggle_display();
    /// CHECK IF GAME IS OVER ///
    if (num_alive == 0)
    {
      *game_active = 0;
      display_set_string("ALL AIRCRAFT GONE. BOO-YAH ");
    }
  }
}

/*********************************************************************************************
 * @brief Handles the game's waiting/menu state
 *
 * Displays the menu screen and waits for player input to start the game.
 * Controls LED indicators and rotating display text.
 *
 * @param frame_counter Current frame number
 * @param game_active Pointer to game state flag
 * @return void
 *********************************************************************************************/
void game_process_wait(uint32_t frame_counter, uint32_t *game_active)
{

  if (frame_counter % 20 == 0)
  {
    display_print_and_rotate_string();
  }
  if (frame_counter % 60 == 0)
    controller_led_turn_on();
  if (frame_counter % 60 == 8)
    controller_led_turn_off();

  button_read(&controller);
  if (controller.fire)
  {
    controller_led_turn_on();
    *game_active = 1;
  }
}
