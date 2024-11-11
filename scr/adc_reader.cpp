#include "em_adc.h"
#include "em_cmu.h"

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
  initScan.input = ADC_SCANCTRL_INPUTMASK_CH0 | ADC_SCANCTRL_INPUTMASK_CH1 | ADC_SCANCTRL_INPUTMASK_CH2;
  ADC_InitScan(ADC0, &initScan);
}

volatile uint32_t * read_adc()
{
  static volatile uint32_t adcSamples[3];

  ADC_Start(ADC0, adcStartScan);

  // Wait for the scan conversion to complete
  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSamples[0] = ADC0->SCANDATA;

  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSamples[1] = ADC0->SCANDATA;

  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSamples[2] = ADC0->SCANDATA;

  // Convert thumbstick voltages to values in range [-0.5, 0.5]

  adcSamples[0] = (adcSamples[0]*3300)/4095; // Convert to voltage
  adcSamples[1] = (adcSamples[1]*3300)/4095; // Convert to voltage
  adcSamples[2] = (adcSamples[2]*3300)/4095; // Convert to voltage

  return adcSamples;
}


long double * voltage_to_controllerValue(volatile uint32_t * adcValues)
{
  static long double controllerValues[3];

  if (adcValues[0] < 1400 || 1600 < adcValues[0])
      controllerValues[0] = adcValues[0] / 3300.0 - 0.5;
  else
      controllerValues[0] = 0.0;

  if (adcValues[1] < 1400 || 1600 < adcValues[1])
      controllerValues[1] = adcValues[1] / 3300.0 - 0.5;
  else
      controllerValues[1] = 0.0;

  if (adcValues[2]<3100)
    controllerValues[2] = 0.0;
  else if (3100 <= adcValues[2] && adcValues[2] < 3150)
    controllerValues[2] = 0.25;
  else if (3150 <= adcValues[2] && adcValues[2] < 3170)
    controllerValues[2] = 0.50;
  else if (3170 <= adcValues[2] && adcValues[2] < 3180)
    controllerValues[2] = 0.75;
  else
    controllerValues[2] = 1.0;

  return controllerValues;
}
