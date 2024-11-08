#include "sl_sleeptimer.h"

#include "display.h"
#include "game.h"

#ifndef FPS
#define FPS 60
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif

sl_sleeptimer_timer_handle_t timer;
int iteration = 0;
uint8_t chars[6] = {0x46, 0x55, 0x43, 0x4B, 0x10, 0x10};

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
    display_init();
    // Calculate the number of ticks needed for 60 FPS
    uint32_t toggle_delay_ticks = calculate_ticks_per_frame();
    sl_led_toggle(&LED_INSTANCE_0);
    sl_led_toggle(&LED_INSTANCE_1);

    // Start a periodic timer using ticks to achieve precise 60 FPS
    sl_sleeptimer_start_periodic_timer(&timer,
                                       toggle_delay_ticks,
                                       on_timeout,
                                       NULL,
                                       0,
                                       SL_SLEEPTIMER_NO_HIGH_PRECISION_HF_CLOCKS_REQUIRED_FLAG);

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

    display_write_data(0x60, chars[6 % iteration]);
    display_write_data(0x61, chars[6 % iteration + 1]);
    display_write_data(0x62, chars[6 % iteration + 2]);
    display_write_data(0x63, chars[6 % iteration + 3]);
    display_write_data(0x64, chars[6 % iteration + 4]);
    display_write_data(0x65, chars[6 % iteration + 5]);
    iteration = iteration + 1;

    frame_ready = true;

}
