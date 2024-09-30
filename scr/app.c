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
#include "spi.h"
#include <stdio.h>
#include <string.h>
#include "sl_simple_led_instances.h"
#include "sl_simple_button_instances.h"

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


/******************************************************************************
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  // Initialize SPI, on usart1

  // master
  // spi_init();

  // slave
  spi_slave_init();

  
  
}


/******************************************************************************
 * App ticking function. For Slave
 ******************************************************************************/
void app_process_action(void)
{


  uint8_t buffer =0;



  sl_led_toggle(&LED_INSTANCE_0);



      Ecode_t ret = spi_slave_receive(&buffer, 1);

      if (ret != ECODE_EMDRV_SPIDRV_OK) {
      sl_led_toggle(&LED_INSTANCE_0);
      }
      else if(ret == ECODE_EMDRV_SPIDRV_OK){
        sl_led_toggle(&LED_INSTANCE_1);
      }

      // if(*buffer !=0){
      //   sl_led_toggle(&LED_INSTANCE_0);
      // }


    // if (ret != ECODE_OK) {
    //   sl_led_toggle(&LED_INSTANCE_0);
    // }
    // else if(ret == ECODE_OK){
    //   sl_led_toggle(&LED_INSTANCE_1);
    // }

}


/******************************************************************************
 * App ticking function. For Master
LoadFile /Users/arash/Documents/MCU/build/debug/flying_soft.hex
******************************************************************************/
// void app_process_action(void)
// {

//     uint8_t buffer = 1;
//   // if (sl_button_get_state(&sl_button_btn1) == SL_SIMPLE_BUTTON_PRESSED){

//   //   sl_led_toggle(&LED_INSTANCE_0);
//   //   spi_transfer(buffer, 1);
//   // }

//   if (sl_button_get_state(&sl_button_btn1) == SL_SIMPLE_BUTTON_PRESSED){
//     Ecode_t ret = spi_transfer(buffer, 1);
//     if (ret != ECODE_OK) {
//       sl_led_toggle(&LED_INSTANCE_0);
//     }
//     else if(ret == ECODE_OK){
//       sl_led_toggle(&LED_INSTANCE_1);
//     }
//   }
  
// }

