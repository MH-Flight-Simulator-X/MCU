#include "adc_reader.h"
#include "em_adc.h"
#include "em_cmu.h"
#include "sl_simple_led_instances.h"
#include <efm32gg990f1024.h>
#include <sleeptimer_app.h>
#include <stdint.h>
#include <stdio.h>

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif


uint32_t sample;
uint32_t adcFreq = 8192;

void initADC(void)
{
  sl_led_toggle(&LED_INSTANCE_0);

  // Enable ADC0 clock
  CMU_ClockEnable(cmuClock_ADC0, true);

  // Declare structures
  ADC_Init_TypeDef       init = ADC_INIT_DEFAULT;
  // ADC_InitScan_TypeDef   initScan = ADC_INITSCAN_DEFAULT;
  ADC_InitSingle_TypeDef initSingle = ADC_INITSINGLE_DEFAULT;

  init.prescale = ADC_PrescaleCalc(adcFreq, 0);
  init.timebase = ADC_TimebaseCalc(0);

  // initScan.diff = false;
  // initScan.reference = adcRef2V5;
  // initScan.resolution = adcRes12Bit;

  initSingle.diff = false;
  initSingle.reference = adcRef2V5;


  // initScan.input = ADC_SCANCTRL_INPUTMASK_CH0 | _ADC_SCANCTRL_INPUTMASK_CH1;
  initSingle.input = ADC_SCANCTRL_INPUTMASK_CH0 | _ADC_SCANCTRL_INPUTMASK_CH1;

  // init.ovsRateSel = adcOvsRateSel1024;
  init.lpfMode = adcLPFilterDeCap;
  init.warmUpMode = adcWarmupKeepADCWarm;

  ADC_Init(ADC0, &init);
  ADC_InitScan(ADC0, &initScan);

  ADC_IntEnable(ADC0, ADC_IEN_SCAN);

  NVIC_ClearPendingIRQ(ADC0_IRQn);
  NVIC_EnableIRQ(ADC0_IRQn);
}

void toggle_led(void)
{
  sl_led_toggle(&LED_INSTANCE_0);

  ADC_Start(ADC0, adcStartScan);
  while (ADC0->STATUS & ADC_STATUS_SCANDV);
  uint32_t sample = ADC_DataScanGet(ADC0);

  if (sample > 819)
  {
    sl_led_toggle(&LED_INSTANCE_0);
  }
}