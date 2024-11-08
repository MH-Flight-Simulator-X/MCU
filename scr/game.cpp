#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "game.h"
#include "display.h"


int iteration = 0;
uint8_t chars[6] = {0x46, 0x55, 0x43, 0x4B, 0x10, 0x10};


void game_init()
{
    display_init();
}

void game_process_action(uint32_t frame_counter)
{
    if (frame_counter % 30 == 0) {

      display_write_data(0x60, chars[6 % iteration]);
      display_write_data(0x61, chars[6 % iteration + 1]);
      display_write_data(0x62, chars[6 % iteration + 2]);
      display_write_data(0x63, chars[6 % iteration + 3]);
      display_write_data(0x64, chars[6 % iteration + 4]);
      display_write_data(0x65, chars[6 % iteration + 5]);
      iteration = iteration + 1;
    }
}
