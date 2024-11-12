#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "plane.h"
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
Plane plane;
Controller controller;

void game_init()
{
  display_init();
  adc_init();
  init_plane(&plane);
}

void game_process_action(uint32_t frame_counter)
{

  get_controller_inputs(&controller);

  if (controller.pitch > 0)
  {
    sl_led_turn_on(&LED_INSTANCE_0);
  }
  else
  {
    sl_led_turn_off(&LED_INSTANCE_0);
  }
  if (controller.roll > 0)
  {
    sl_led_turn_on(&LED_INSTANCE_1);
  }
  else
  {
    sl_led_turn_off(&LED_INSTANCE_1);
  }

  update_plane(&plane, &controller);
  
  if (frame_counter % 30 == 0) {
    display_print_testing(iteration);
    iteration = iteration + 1;
  }
}
