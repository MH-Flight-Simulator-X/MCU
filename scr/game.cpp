#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "game.h"
#include "display.h"
#include "adc_reader.h"

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif


#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif


int iteration = 0;
uint8_t chars[6] = {0x46, 0x55, 0x43, 0x4B, 0x10, 0x10};


void game_init()
{
    display_init();
    adc_init();
}

void game_process_action(uint32_t frame_counter)
{

  volatile uint32_t * adcValues;
  long double * controllerValues;
  adcValues = read_adc();
  controllerValues = voltage_to_controllerValue(adcValues);

  if (controllerValues[0] > 0 )
  {
    sl_led_turn_on(&LED_INSTANCE_0);
  }
  else
  {
    sl_led_turn_off(&LED_INSTANCE_0);
  }
  if (controllerValues[1] > 0)
  {
    sl_led_turn_on(&LED_INSTANCE_1);
  }
  else
  {
    sl_led_turn_off(&LED_INSTANCE_1);
  }

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
