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
/*********************************************************************************************
 * @file    app.c
 * @brief   Main application control for the MicroHard Flight Simulator
 * 
 * This file handles the core application loop, frame timing, and game state management.
 * It coordinates between the game logic and display components while maintaining
 * a consistent frame rate for the simulation.
 *
 * @note    Target FPS is defined in app.h
 *********************************************************************************************/


#include "sl_sleeptimer.h"
#include "game.h"
#include "app.h"
#include "display.h"

/*********************************************************************************************
 * @brief   Global Variables
 *********************************************************************************************/
sl_sleeptimer_timer_handle_t frame_timer;     /**< Timer handle for frame rate control */
bool frame_ready = false;                     /**< Flag indicating if a new frame should be processed */
uint32_t frame_counter = 0;                   /**< Counter tracking total frames since start */
uint32_t game_active;                         /**< Game state flag (0 = waiting, 1 = active) */

/*********************************************************************************************
 * @brief   Frame timer callback function
 * @param   handle  Pointer to the timer handle
 * @param   data    User data (unused)
 * 
 * Called when the frame timer expires. Sets frame_ready flag to trigger next frame processing.
 *********************************************************************************************/
static void on_frame_timeout(sl_sleeptimer_timer_handle_t *handle, void *data)
{
  (void)handle;
  (void)data;
  frame_ready = true;
}

/*********************************************************************************************
 * @brief   Initialize the frame timer
 * 
 * Configures and starts a periodic timer to maintain consistent frame rate based on
 * the defined FPS value.
 *********************************************************************************************/
void frame_timer_init()
{
  uint32_t timer_frequency = sl_sleeptimer_get_timer_frequency();
  uint32_t ticks_per_frame = timer_frequency / FPS;
  sl_sleeptimer_start_periodic_timer(&frame_timer, ticks_per_frame, on_frame_timeout, NULL, 0, SL_SLEEPTIMER_NO_HIGH_PRECISION_HF_CLOCKS_REQUIRED_FLAG);
}

/*********************************************************************************************
 * @brief   Initialize the application
 * 
 * Sets up the frame timer, initializes the game state, and displays the initial
 * waiting message.
 *********************************************************************************************/
void app_init()
{
  frame_timer_init();
  game_init();
  game_active = 0;
  game_process_action(frame_counter, &game_active);
  display_set_string("WAITING TO START MICROHARD FLIGHT SIMULATOR ");
}

/*********************************************************************************************
 * @brief   Process application actions
 * 
 * Main application loop that handles frame-based updates. When a frame is ready:
 * - Increments the frame counter
 * - Processes game actions based on whether the game is active or in waiting state
 *********************************************************************************************/
void app_process_action(void)
{

  if (frame_ready)
  {
    frame_counter++;
    frame_ready = false;
    if (game_active)
      {
        game_process_action(frame_counter, &game_active);
      }
    else
      {
        game_process_wait(frame_counter, &game_active);
      }
  }
}


