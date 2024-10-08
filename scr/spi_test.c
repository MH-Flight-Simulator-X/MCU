#include "physics_engine.h"
#include "sl_iostream_init_instances.h"
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
#include "spi.h"
#include <stdio.h>
#include <string.h>

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
  size_t  buffer_size = sizeof(object_t);
  uint8_t buffer[buffer_size];

  object_t object = {.x = 10, .y = 15, .z = 20, .dx = 1, .dy = 2, .dz = 3, .hp = 100};
  force_t  force = {.amplitude = 5, .x = 2, .y = -1, .z = 3};

  apply_force(&object, &force);

  memcpy(buffer, &object, buffer_size);

  for (size_t i = 0; i < buffer_size; i++)
  {
    printf("%02X ", buffer[i]);
  }

  if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED)
  {
    if (&BUTTON_INSTANCE_1 == handle)
    {
      spi_transfer(&buffer, buffer_size);
      sl_led_toggle(&LED_INSTANCE_1);
    }
    if (&BUTTON_INSTANCE_0 == handle)
    {
      sl_led_toggle(&LED_INSTANCE_0);
    }
  }
}
