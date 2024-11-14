
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>
#include <sl_button.h>


typedef struct
{
  double pitch;
  double roll;
  double throttle;
  int fire;
} Controller;

void adc_init(void);
void adc_read(uint32_t *adcSamples);
void controller_init(Controller * controller);
void controller_get_inputs(Controller *controller, uint32_t frame_counter);
void controller_convert_voltage(volatile uint32_t *adcValues, Controller *controller);
void controller_fire_active();
void button_init();
void button_read(Controller * controller);


#endif  // CONTROLLER_H
