#include <fpga_spi.h>
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
#include "transformation.h"
#include <stdio.h>
#include "debug.h"
#include <string.h>

#ifndef BUTTON_INSTANCE_0
#define BUTTON_INSTANCE_0 sl_button_btn0
#endif

#ifndef BUTTON_INSTANCE_1
#define BUTTON_INSTANCE_1 sl_button_btn1
#endif

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif



void sl_button_on_change(const sl_button_t *handle)
{
  if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED)
  {
    if (&BUTTON_INSTANCE_1 == handle)
    {
      sl_led_toggle(&LED_INSTANCE_1);
      debug_print("Knapp 1 trykket");
      display_toggle_display();
    }
    if (&BUTTON_INSTANCE_0 == handle)
    {
      sl_led_toggle(&LED_INSTANCE_0);
    }
  }
}
