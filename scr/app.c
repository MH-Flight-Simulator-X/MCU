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
#include "physics_engine.h"
#include "spi.h"

/******************************************************************************
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  // Initialize SPI, on usart1
  spi_init();
}

/******************************************************************************
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  // sleeptimer_app_process_action();
  run();
}
