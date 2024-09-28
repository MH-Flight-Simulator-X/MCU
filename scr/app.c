/******************************************************************************
 * @file
 * @brief Top level application functions
 ******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
// #include "sleeptimer_app.h"
// #include "spi_slave.h"
#include "spi_slave.h"
#include <stdio.h>
#include <string.h>
#include "sl_simple_led_instances.h"

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

/******************************************************************************
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  // Initialize SPI, on usart1
  spi_slave_init();

  
  
}

/******************************************************************************
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{

  uint8_t buffer;
  spi_slave_receive(&buffer, 1);
  if (buffer == 1)
    {
      sl_led_toggle(&LED_INSTANCE_0);
    }
}
