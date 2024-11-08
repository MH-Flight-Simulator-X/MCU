#include "sl_sleeptimer.h"
#include "game.h"

#ifndef FPS
#define FPS 60
#endif

sl_sleeptimer_timer_handle_t frame_timer;
bool frame_ready = false;
uint32_t frame_counter = 0;

static void on_frame_timeout(sl_sleeptimer_timer_handle_t *handle, void *data);

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
}

void app_process_action(void)
{
    if (frame_ready)
    {
        frame_counter++;
        game_process_action(frame_counter);
        frame_ready = false;
    }
}

static void on_frame_timeout(sl_sleeptimer_timer_handle_t *handle, void *data)
{
    (void)handle;
    (void)data;
    frame_ready = true;
}
