#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "sl_sleeptimer.h"
#include "display.h"

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif

sl_sleeptimer_timer_handle_t timer;
sl_sleeptimer_timer_handle_t display_timer;
bool toggle_timeout = false;
int iteration = 0;
uint8_t chars[6] = {0x46, 0x55, 0x43, 0x4B, 0x10, 0x10};

// Function prototype for the timer callback
static void on_timeout(sl_sleeptimer_timer_handle_t *handle, void *data);

// Function to calculate ticks for one frame (60 FPS)
static uint32_t calculate_ticks_per_frame(void)
{
    // Get the timer frequency in ticks per second
    uint32_t timer_frequency = sl_sleeptimer_get_timer_frequency();
    // Calculate ticks for 1/60th of a second (16.6667 ms)
    uint32_t ticks_per_frame = timer_frequency / 10;
    return ticks_per_frame;
}

void app_init(void)
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
}

void app_process_action(void)
{
    if (toggle_timeout)
    {
        sl_led_toggle(&LED_INSTANCE_0);
        toggle_timeout = false;
    }
}

static void on_timeout(sl_sleeptimer_timer_handle_t *handle, void *data)
{
    (void)handle;
    (void)data;
    toggle_timeout = true;

    display_write_data(0x60, chars[6 % iteration]);
    display_write_data(0x61, chars[6 % iteration + 1]);
    display_write_data(0x62, chars[6 % iteration + 2]);
    display_write_data(0x63, chars[6 % iteration + 3]);
    display_write_data(0x64, chars[6 % iteration + 4]);
    display_write_data(0x65, chars[6 % iteration + 5]);

    iteration = iteration + 1;
}
