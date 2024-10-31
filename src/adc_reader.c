#include "adc_reader.h"
#include "em_adc.h"
#include "em_cmu.h"
#include "em_system.h"
#include "em_timer.h"
#include "sl_simple_led_instances.h"
#include <efm32gg990f1024.h>
#include <segmentlcd.h>
#include <stdint.h>
#include <stdio.h>

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif

#define adc_init_single ADC_INITSINGLE_DEFAULT;
#define LED_INSTANCE_0 sl_led_led0

volatile uint32_t adcSample = 0;
volatile bool     adcSampleReady = false;
uint32_t          temp;

void ADC0_IRQHandler(void)
{
  /* Read conversion result to clear Single Data Valid flag */
  adcSample = ADC_DataScanGet(ADC0);
  adcSample = (adcSample * 3300) / 4095;
  SegmentLCD_LowerNumber(adcSample);
  if (adcSample > 1500)
  {
    sl_led_turn_on(&LED_INSTANCE_0);
    sl_led_turn_off(&LED_INSTANCE_1);
  }
  else
  {
    sl_led_turn_off(&LED_INSTANCE_0);
    sl_led_turn_on(&LED_INSTANCE_1);
  }
  /* Clear ADC0 interrupt flag */
}

void init_adc()
{
  CMU_ClockEnable(cmuClock_ADC0, true);

  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  ADC_Init(ADC0, &init);

  ADC_InitScan_TypeDef initScan = ADC_INITSCAN_DEFAULT;
  initScan.reference = adcRefVDD;
  initScan.resolution = adcRes12Bit;
  initScan.input = ADC_SCANCTRL_INPUTMASK_CH0 | ADC_SCANCTRL_INPUTMASK_CH1 | ADC_SCANCTRL_INPUTMASK_CH2;
  ADC_InitScan(ADC0, &initScan);

  ADC_IntEnable(ADC0, ADC_IEN_SCAN);
  ADC_IntEnable(ADC0, ADC_IEN_SCANOF);
  NVIC_EnableIRQ(ADC0_IRQn);

  ADC_Start(ADC0, adcStartSingle);
}

void read_adc()
{

  if (adcSampleReady)
  {
    adcSampleReady = false;
    ADC_Reset(ADC0);
    // temp = adcSample / 4095;
    // adcSample = temp * 3300;
  }
}
