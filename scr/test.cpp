#include <fpga_spi.h>
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
#include "transformation.h"
#include <stdio.h>
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
      //MvpMatrixEntry entries[2];

      vec3 position1 = {1.0f, 2.0f, 3.0f};
      //generate_mvp_matrix_entry(position1, 0.5f, 1.0f, 0xA, 0x1, &entries[0]);

      vec3 position2 = {4.0f, 5.0f, 6.0f};
      //generate_mvp_matrix_entry(position2, 0.7f, 1.5f, 0xB, 0x2, &entries[1]);

      //fpga_frame_send(entries, 2);
    }
    if (&BUTTON_INSTANCE_0 == handle)
    {
      sl_led_toggle(&LED_INSTANCE_0);
    }
  }
}
