#include <stdio.h>
#include <string.h>
#include "sleeptimer_app.h"
#include "sl_sleeptimer.h"
#include "sl_simple_led_instances.h"
#include "sl_simple_button_instances.h"
#include "sl_iostream_init_instances.h"

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

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

#define APP_BUFFER_SIZE 16

void sl_button_on_change(const sl_button_t *handle)
{
  uint8_t buffer[16];
  for (int i = 0; i < 16; i++) {
    buffer[i] = i;
  }
  bool is_running = false;
  if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED)
  {
    if (&BUTTON_INSTANCE_1 == handle)
    {
      spi_transfer(&(buffer[i]), 16);
      sl_led_toggle(&LED_INSTANCE_1);
    }
    if (&BUTTON_INSTANCE_0 == handle)
    {
      sl_led_toggle(&LED_INSTANCE_0);
    }
  }
}
