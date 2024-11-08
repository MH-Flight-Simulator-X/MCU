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

void sl_button_on_change(const sl_button_t *handle) {
  if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED) {

    if (&BUTTON_INSTANCE_1 == handle) {
      // Send the array over SPI directly using spi_transfer
//      spi_transfer(plane_obj, plane_obj_len);

      // Turn on LED_INSTANCE_1 to indicate the transfer was triggered
      sl_led_toggle(&LED_INSTANCE_1);
    }

    // Toggle LED_INSTANCE_0 if BUTTON_INSTANCE_0 was pressed (unrelated functionality)
    if (&BUTTON_INSTANCE_0 == handle) {
      sl_led_toggle(&LED_INSTANCE_0);
    }
  }
}

