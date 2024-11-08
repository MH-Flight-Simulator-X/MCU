/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "blink.h"
#include "adc_reader.h"


/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init()
{
//  blink_init();
  init_adc();
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action()
{
//  blink_process_action();
//  Start_ADC_Conversion_PD0();
  read_adc();
}
