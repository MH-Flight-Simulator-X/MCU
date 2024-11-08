#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "sl_sleeptimer.h"

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif

sl_sleeptimer_timer_handle_t timer;
bool toggle_timeout = false;

// Function prototype for the timer callback
static void on_timeout(sl_sleeptimer_timer_handle_t *handle, void *data);

// Function to calculate ticks for one frame (60 FPS)
static uint32_t calculate_ticks_per_frame(void)
{
    // Get the timer frequency in ticks per second
    uint32_t timer_frequency = sl_sleeptimer_get_timer_frequency();
    // Calculate ticks for 1/60th of a second (16.6667 ms)
    uint32_t ticks_per_frame = timer_frequency / 60;
    return ticks_per_frame;
}

void app_init(void)
{
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
        sl_led_toggle(&LED_INSTANCE_1);
        toggle_timeout = false;
    }
}

static void on_timeout(sl_sleeptimer_timer_handle_t *handle, void *data)
{
    (void)handle;
    (void)data;
    toggle_timeout = true;
}
