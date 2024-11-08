#include "adc_reader.h"
#include "em_adc.h"
#include "em_cmu.h"
#include "em_system.h"
#include "em_timer.h"
#include "sl_simple_led_instances.h"
#include <stdint.h>
#include <stdio.h>


#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif

volatile uint32_t adcSample = 0;
volatile bool     adcSampleReady = false;
uint32_t          temp;

void init_adc()
{
  CMU_ClockEnable(cmuClock_ADC0, true);
  CMU_ClockEnable(cmuClock_GPIO, true);


  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  init.timebase = ADC_TimebaseCalc(0);
  init.prescale = ADC_PrescaleCalc(4000000, 0);  // 4 MHz ADC clock
//  init.warmUpMode = adcWarmupKeepADCWarm;
  ADC_Init(ADC0, &init);

  ADC_InitScan_TypeDef initScan = ADC_INITSCAN_DEFAULT;
  initScan.reference = adcRefVDD;
  //initScan.input = adcSingleInputCh0; // | ADC_SCANCTRL_INPUTMASK_CH1 | ADC_SCANCTRL_INPUTMASK_CH2;
  //initScan.rep = true;
  initScan.acqTime = adcAcqTime16;
  initScan.input = ADC_SCANCTRL_INPUTMASK_CH0 | ADC_SCANCTRL_INPUTMASK_CH1;   // Enable PD1
                     //| ADC_SCANCTRL_INPUTMASK_CH2; // Enable PD2
  ADC_InitScan(ADC0, &initScan);



}

volatile uint32_t adcSample0;
volatile uint32_t adcSample1;

void read_adc()
{

  ADC_Start(ADC0, adcStartScan);

  // Wait for the scan conversion to complete
  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSample0 = ADC0->SCANDATA;
  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSample1 = ADC0->SCANDATA;

  adcSample0 = (adcSample0 * 3300) / 4095;
  adcSample1 = (adcSample1 * 3300) / 4095;

  if (adcSample0 > 1500)
  {
    sl_led_turn_on(&LED_INSTANCE_0);
  }
  else
  {
    sl_led_turn_off(&LED_INSTANCE_0);
  }
  if (adcSample1 > 1500)
  {
    sl_led_turn_on(&LED_INSTANCE_1);
  }
  else
  {
    sl_led_turn_off(&LED_INSTANCE_1);
  }
}
