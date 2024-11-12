
#ifndef ADC_READER_H
#define ADC_READER_H

#include <stdint.h>

typedef struct
{
  long double pitch;
  long double roll;
  long double throttle;
} Controller;

void adc_init(void);
void read_adc(uint32_t *adcSamples);
void get_controller_inputs(Controller *controller);
void voltage_to_controller(volatile uint32_t *adcValues, Controller *controller);


#endif  // ADC_READER_H


