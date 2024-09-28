#include <stdio.h>
#include <string.h>
#include "sl_simple_led_instances.h"
#include "spi_slave.h"
#include "spi_receive.h"


#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif


void spi_slave_run(void)
  {
    uint8_t buffer;
    spi_slave_receive(&buffer, 1);
    if (buffer == 1)
      {
        sl_led_toggle(&LED_INSTANCE_0);
      }
    
}