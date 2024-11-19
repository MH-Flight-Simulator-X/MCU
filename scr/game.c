#include "../include/cglm/cglm.h"
#include <string.h>
#include <stdio.h>
#include "aircraft.h"
#include "ai_aircraft.h"
#include "ai_aircraft_init.h"
#include "controller.h"
#include "game.h"
#include "debug.h"
#include "display.h"
#include "transformation.h"
#include "spi.h"
#include "fpga_spi.h"
#include "fpga.h"

int iteration = 0;
Aircraft aircraft;              // The player's aircraft
Controller controller;          // The controller
AiAircraft *ai_aircraft;        // The "enemy" aircraft
MvpMatrixEntry *matrix_entries; // The MVP matrices for all aircraft

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
  ai_aircraft_create(ai_aircraft, original_aircraft, num_aircraft);
  ai_aircraft_init(ai_aircraft, num_aircraft);

  // ALLOCATE MATRIX ENTRIES
  matrix_entries = (MvpMatrixEntry *)malloc((num_aircraft + 1) * sizeof(MvpMatrixEntry));

  display_set_string("WAITING TO START MICROHARD FLIGHT SIMULATOR ");
}

void game_process_action(uint32_t frame_counter, uint32_t *game_active)
{
  controller_get_inputs(&controller, frame_counter);

  if (controller.fire)
  {
    controller.fire = 0;
    aircraft_check_hit(&aircraft, ai_aircraft, num_aircraft);
  }

  ai_aircraft_update_status(ai_aircraft, num_aircraft); // Update status or counter for ai aircraft

  aircraft_update_pose(&aircraft, &controller); // Update pose on player aircraft

  ai_aircraft_update_pose(ai_aircraft, num_aircraft, frame_counter); // Update pose of remaining ai aircraft

  /// GENERATE MATRICES FOR PLAYER AND AI AIRCRAFT ///
  matrix_entries[0].flag_id = 0x0; // 66 // 00000000
  generate_mvp_matrix((Sprite *)&aircraft, &aircraft, matrix_entries[0].mvp_matrix);

  uint8_t num_alive = 0;
  for (int i = 0; i < num_aircraft; i++)
  {
    uint8_t flag = ai_aircraft[i].status;
    if (flag == 2)
      continue;
    uint8_t id = ai_aircraft[i].id;
    matrix_entries[num_alive + 1].flag_id = flag | id;
    generate_mvp_matrix((Sprite *)&ai_aircraft[i], &aircraft, matrix_entries[num_alive + 1].mvp_matrix);
    num_alive++;
  }

  /// SEND NEW MATRICES TO FPGA ///
  fpga_frame_send(matrix_entries, num_alive);

  /// UPDATE DISPLAY ///
  if (frame_counter % 30 == 0)
  {
    display_set_number();
    display_print_string();
  }
  /// TOGGLE DISPLAY NUMBER ///
  if (frame_counter % 120 == 0)
  {
    display_toggle_display();
    /// CHECK IF GAME IS OVER ///
    if (num_alive == 0)
    {
      *game_active = 0;
      display_set_string("ALL AIRCRAFT GONE. BOO-YAH ");
    }
  }

  void game_process_wait(uint32_t frame_counter, uint32_t *game_active)
  {

    if (frame_counter % 20 == 0)
    {
      display_print_and_rotate_string();
      controller_led_turn_on();
    }
    if ((frame_counter + 5) % 60 == 0)
    {
      controller_led_turn_off();
    }
    button_read(&controller);
    if (controller.fire)
    {
      controller_led_turn_on();
      *game_active = 1;
    }
  }
