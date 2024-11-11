<<<<<<< HEAD
#include "sl_sleeptimer.h"

#include "game.h"
=======
<<<<<<< Updated upstream
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
=======
#include "sl_sleeptimer.h"
#include "game.h"
#include "adc_reader.h"
#include "sl_simple_led_instances.h"
<<<<<<< Updated upstream
=======

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif
>>>>>>> Stashed changes

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif
>>>>>>> Stashed changes
>>>>>>> b490301 (Added return type to ADC function)

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
<<<<<<< HEAD
    frame_timer_init();
    game_init();
<<<<<<< HEAD

=======
=======
<<<<<<< Updated upstream
//  blink_init();
  init_adc();
=======
    frame_timer_init();
    //game_init();
    adc_init();
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
>>>>>>> b490301 (Added return type to ADC function)
>>>>>>> a518586 (Added return type to ADC function)
}

void app_process_action(void)
{
<<<<<<< HEAD
    if (frame_ready)
    {
        frame_counter++;
<<<<<<< HEAD
=======
        game_process_action(frame_counter);
=======
<<<<<<< Updated upstream
//  blink_process_action();
//  Start_ADC_Conversion_PD0();
  read_adc();
=======
    if (frame_ready)
    {
        frame_counter++;
        uint32_t controllerValues = read_adc();
        if (controllerValues[0] > 0)
        {
          sl_led_turn_on(&LED_INSTANCE_0);
        }
        else
        {
          sl_led_turn_off(&LED_INSTANCE_0);
        }
        if (controllerValues[1] > 0)
        {
          sl_led_turn_on(&LED_INSTANCE_1);
        }
        else
        {
          sl_led_turn_off(&LED_INSTANCE_1);
        }
        //game_process_action(frame_counter);
>>>>>>> b490301 (Added return type to ADC function)
>>>>>>> a518586 (Added return type to ADC function)
        frame_ready = false;
        game_process_action(frame_counter);
    }
}

static void on_frame_timeout(sl_sleeptimer_timer_handle_t *handle, void *data)
{
    (void)handle;
    (void)data;
    frame_ready = true;
<<<<<<< HEAD

=======
<<<<<<< HEAD
=======
>>>>>>> Stashed changes
>>>>>>> b490301 (Added return type to ADC function)
>>>>>>> a518586 (Added return type to ADC function)
}
