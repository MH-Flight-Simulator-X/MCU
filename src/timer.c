#include "em_cmu.h"
#include "em_timer.h"

void init_timer(int frequency)
{
  CMU_ClockEnable(cmuClock_TIMER1, true);
  TIMER_Init_TypeDef init = TIMER_INIT_DEFAULT;
  init.enable = false;
  init.prescale = timerPrescale1024;
  TIMER_Init(TIMER1, &init);
  uint32_t top = CMU_ClockFreqGet(cmuClock_TIMER1) / (1024 * frequency);
  TIMER_TopSet(TIMER1, top);
  TIMER_IntEnable(TIMER1, TIMER_IEN_OF);
  NVIC_EnableIRQ(TIMER1_IRQn);
}
