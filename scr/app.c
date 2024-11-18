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
#include "sl_sleeptimer.h"
#include "game.h"
#include "sl_sleeptimer.h"
#include "game.h"
#include "em_gpio.h"

#ifndef FPS
#define FPS 60
#endif


sl_sleeptimer_timer_handle_t frame_timer;
bool frame_ready = false;
uint32_t frame_counter = 0;


static void on_frame_timeout(sl_sleeptimer_timer_handle_t *handle, void *data);

void frame_timer_init()
{
    uint32_t timer_frequency = sl_sleeptimer_get_timer_frequency();
    uint32_t ticks_per_frame = timer_frequency / FPS;
    sl_sleeptimer_start_periodic_timer(&frame_timer, ticks_per_frame, on_frame_timeout, NULL, 0, SL_SLEEPTIMER_NO_HIGH_PRECISION_HF_CLOCKS_REQUIRED_FLAG);
}

void app_init()
{
//  GPIO_PinModeSet(gpioPortE, 13, gpioModePushPull, 0);
//  GPIO_PinModeSet(gpioPortA, 2, gpioModePushPull, 0);
  //spi_init();
  frame_timer_init();
  game_init();
}

void app_process_action(void)
{

//  if (frame_counter % 120 == 0)
//    GPIO_PinOutSet(gpioPortE, 13);
//  else
//    GPIO_PinOutClear(gpioPortE, 13);

  if (frame_ready)
  {
    frame_counter++;
    frame_ready = false;
    game_process_action(frame_counter);
  }
}

static void on_frame_timeout(sl_sleeptimer_timer_handle_t *handle, void *data)
{
    (void)handle;
    (void)data;
    frame_ready = true;
}
