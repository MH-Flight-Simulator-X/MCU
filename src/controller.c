#include <controller.h>
#include "em_adc.h"
#include "em_cmu.h"
#include "sl_button.h"
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
#include "em_gpio.h"
#include "sl_simple_led_instances.h"

#include "debug.h"
#include "sl_led.h"

void controller_init(Controller *controller)
{
  controller->pitch = 0;
  controller->roll = 0;
  controller->throttle = 0.5;
  controller->fire = 0;

  adc_init();
}

void controller_get_inputs(Controller *controller, uint32_t frame_counter)
{
  uint32_t adcSamples[3];
  adc_read(adcSamples);
  controller_convert_voltage(adcSamples, controller);

  button_read(controller);

  //  if (frame_counter % 30 == 0)
  //  {
  //      debug_print_float((float)adcSamples[1]);
  //      debug_print_float((float)adcSamples[0]);
  //      debug_print_float((float)adcSamples[2]);
  //      debug_printf("\n");
  //  }
}

void controller_convert_voltage(volatile uint32_t *adcValues, Controller *controller)
{
  // CONVERT THUMBSTICK TO PITCH
  if (adcValues[0] < 1200 || 1800 < adcValues[0])
    controller->roll = adcValues[0] / 3300.0 - 0.5;
  else
    controller->roll = 0.0;

  // CONVERT THUMBSTICK TO ROLL
  if (adcValues[1] < 1200 || 1800 < adcValues[1])
    controller->pitch = adcValues[1] / 3300.0 - 0.5;
  else
    controller->pitch = 0.0;

  // CONVERT SLIDER TO THROTTLE
  if (adcValues[2] < 3100)
    controller->throttle = 0.0;
  else if (3100 <= adcValues[2] && adcValues[2] < 3150)
    controller->throttle = 0.25;
  else if (3150 <= adcValues[2] && adcValues[2] < 3170)
    controller->throttle = 0.50;
  else if (3170 <= adcValues[2] && adcValues[2] < 3180)
    controller->throttle = 0.75;
  else
    controller->throttle = 1.0;
}

// Initialize ADC
void adc_init()
{
  CMU_ClockEnable(cmuClock_ADC0, true);

  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  init.timebase = ADC_TimebaseCalc(0);
  init.prescale = ADC_PrescaleCalc(4000000, 0); // 6 kHz ADC clock
  ADC_Init(ADC0, &init);

  ADC_InitScan_TypeDef initScan = ADC_INITSCAN_DEFAULT;
  initScan.reference = adcRefVDD; // Set reference voltage to VDD
  initScan.acqTime = adcAcqTime64; // Set acquisition time to 64 ADC clock cycles
  initScan.input = ADC_SCANCTRL_INPUTMASK_CH0 // Use channels 0, 1 and 2 for thumb_x, thumb_y and slider inputs
                  | ADC_SCANCTRL_INPUTMASK_CH1
                  | ADC_SCANCTRL_INPUTMASK_CH2;
  ADC_InitScan(ADC0, &initScan);
}

// Start ADC read, wait for conversions and convert to volts
void adc_read(uint32_t *adcSamples)
{
  ADC_Start(ADC0, adcStartScan);

  while (!(ADC0->STATUS & ADC_STATUS_SCANDV))
    ;
  adcSamples[0] = 3300 - ((ADC0->SCANDATA - 40) * 3300) / 4095;

  while (!(ADC0->STATUS & ADC_STATUS_SCANDV))
    ;
  adcSamples[1] = (ADC0->SCANDATA * 3300) / 4095;

  while (!(ADC0->STATUS & ADC_STATUS_SCANDV))
    ;
  adcSamples[2] = 3300 - (ADC0->SCANDATA * 3300) / 4095;
}

void button_read(Controller *controller)
{
  sl_button_poll_step(&sl_button_fire);
  controller->fire = sl_button_get_state(&sl_button_fire) != SL_SIMPLE_BUTTON_PRESSED;
}

void controller_led_turn_off()
{
  GPIO_PinOutClear(gpioPortD, 4);
}

void controller_led_turn_on()
{
  GPIO_PinOutSet(gpioPortD, 4);
}
