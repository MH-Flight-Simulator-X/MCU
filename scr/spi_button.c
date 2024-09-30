#include <stdio.h>
#include <string.h>
#include "sleeptimer_app.h"
#include "sl_sleeptimer.h"
#include "sl_simple_led_instances.h"
#include "sl_simple_button_instances.h"
#include "sl_iostream_init_instances.h"
#include "spi.h"

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
  uint8_t buffer = 0x01;
  if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED)
  {
      sl_led_toggle(&LED_INSTANCE_0);
      spi_transfer(&buffer, 1);

    // if (&BUTTON_INSTANCE_0 == handle)
    // {
    //   sl_led_toggle(&LED_INSTANCE_1);
    // }
  }
}
