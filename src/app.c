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


#include "sl_sleeptimer.h"
#include "game.h"
#include "app.h"
#include "display.h"

sl_sleeptimer_timer_handle_t frame_timer;
bool frame_ready = false;
uint32_t frame_counter = 0;
uint32_t game_active;

static void on_frame_timeout(sl_sleeptimer_timer_handle_t *handle, void *data)
{
  (void)handle;
  (void)data;
  frame_ready = true;
}

void frame_timer_init()
{
  uint32_t timer_frequency = sl_sleeptimer_get_timer_frequency();
  uint32_t ticks_per_frame = timer_frequency / FPS;
  sl_sleeptimer_start_periodic_timer(&frame_timer, ticks_per_frame, on_frame_timeout, NULL, 0, SL_SLEEPTIMER_NO_HIGH_PRECISION_HF_CLOCKS_REQUIRED_FLAG);
}

void app_init()
{
  frame_timer_init();
  game_init();
  game_active = 0;
  game_process_action(frame_counter, &game_active);
  display_set_string("WAITING TO START MICROHARD FLIGHT SIMULATOR ");
}

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


