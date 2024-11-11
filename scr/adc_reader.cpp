#include "adc_reader.h"
#include "em_adc.h"
#include "em_cmu.h"
#include "em_system.h"
#include "em_timer.h"
#include <stdint.h>
#include <stdio.h>

void adc_init()
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

long double * read_adc()
{
  volatile uint32_t adcSamples[3];
  static long double controllerValues[3];

  ADC_Start(ADC0, adcStartScan);

  // Wait for the scan conversion to complete
  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSamples[0] = ADC0->SCANDATA;
  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSamples[1] = ADC0->SCANDATA;
  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSamples[2] = ADC0->SCANDATA;

  controllerValues[0] = adcSamples[0] / 4095 - 0.5;
  controllerValues[1] = adcSamples[1] / 4095 - 0.5;

  if (adcSamples[2]<3000)
    controllerValues[2] = 0;
  else if (3000 <= adcSamples[2] && adcSamples[2] < 3050)
    controllerValues[2] = 1;
  else if (3050 <= adcSamples[2] && adcSamples[2] < 3100)
    controllerValues[2] = 1.25;
  else if (3100 <= adcSamples[2] && adcSamples[2] < 3150)
    controllerValues[2] = 1.5;
  else if (3200 <= adcSamples[2] && adcSamples[2] < 3250)
    controllerValues[2] = 1.75;
  else
    controllerValues[2] = 2;

  return controllerValues;

}
