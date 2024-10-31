#include "adc_reader.h"
#include "em_cmu.h"
#include "em_timer.h"
#include "timer.h"

int main(void)
{
  init_adc();
  while (1)
  {
    read_adc();
  }
}
