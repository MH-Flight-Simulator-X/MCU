#include "em_adc.h"
#include "em_cmu.h"
#include "adc_reader.h"


void get_controller_inputs(Controller * controller)
{
  uint32_t adcSamples[3];
  read_adc(adcSamples);
  voltage_to_controller(adcSamples, controller);

}

void adc_init()
{
  CMU_ClockEnable(cmuClock_ADC0, true);
  CMU_ClockEnable(cmuClock_GPIO, true);

  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  init.timebase = ADC_TimebaseCalc(0);
  init.prescale = ADC_PrescaleCalc(4000000, 0);  // 4 MHz ADC clock
  ADC_Init(ADC0, &init);

  ADC_InitScan_TypeDef initScan = ADC_INITSCAN_DEFAULT;
  initScan.reference = adcRefVDD;
  initScan.acqTime = adcAcqTime16;
  initScan.input = ADC_SCANCTRL_INPUTMASK_CH0 | ADC_SCANCTRL_INPUTMASK_CH1 | ADC_SCANCTRL_INPUTMASK_CH2;
  ADC_InitScan(ADC0, &initScan);
}


// Start ADC read, wait for conversions and convert to volts
void read_adc(uint32_t * adcSamples)
{
  ADC_Start(ADC0, adcStartScan);

  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSamples[0] = (ADC0->SCANDATA * 3300) / 4095;

  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSamples[1] = (ADC0->SCANDATA * 3300) / 4095;

  while (!(ADC0->STATUS & ADC_STATUS_SCANDV));
  adcSamples[2] = (ADC0->SCANDATA * 3300) / 4095;
}


void voltage_to_controller(volatile uint32_t * adcValues, Controller * controller)
{
  // CONVERT THUMBSTICK TO PITCH
  if (adcValues[0] < 1400 || 1600 < adcValues[0])
    controller->pitch = adcValues[0] / 3300.0 - 0.5;
  else
    controller->pitch = 0.0;

  // CONVERT THUMBSTICK TO ROLL
  if (adcValues[1] < 1400 || 1600 < adcValues[1])
    controller->roll = adcValues[1] / 3300.0 - 0.5;
  else
    controller->roll = 0.0;

  // CONVERT SLIDER TO THROTTLE
  if (adcValues[2]<3100)
    controller->throttle = 0.0;
  else if (3100 <= adcValues[2] && adcValues[2] < 3150)
    controller->throttle = 0.25;
  else if (3150 <= adcValues[2] && adcValues[2] < 3170)
    controller->throttle  = 0.50;
  else if (3170 <= adcValues[2] && adcValues[2] < 3180)
    controller->throttle = 0.75;
  else
    controller->throttle = 1.0;

}
