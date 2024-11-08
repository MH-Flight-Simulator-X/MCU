#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "game.h"

void game_init()
{
    sl_led_turn_off(&sl_led_led0);
    sl_led_turn_off(&sl_led_led1);
}

void game_process_action(uint32_t frame_counter)
{

    // Toggle LED0 every frame
    if (frame_counter % 2 == 0) {
        sl_led_toggle(&sl_led_led0);
    }

    // Toggle LED1 every 30 frames (~ every 0.5 second if running at 60 FPS)
    if (frame_counter % 30 == 0) {
        sl_led_toggle(&sl_led_led1);
    }
}
