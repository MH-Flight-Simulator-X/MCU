#include "sl_emlib_gpio_simple_init.h"
#include "sl_emlib_gpio_init_FPGA_Reset_config.h"
#include "sl_emlib_gpio_init_button_fire_config.h"
#include "sl_emlib_gpio_init_button_led_config.h"
#include "em_gpio.h"
#include "em_cmu.h"

void sl_emlib_gpio_simple_init(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(SL_EMLIB_GPIO_INIT_FPGA_RESET_PORT,
                  SL_EMLIB_GPIO_INIT_FPGA_RESET_PIN,
                  SL_EMLIB_GPIO_INIT_FPGA_RESET_MODE,
                  SL_EMLIB_GPIO_INIT_FPGA_RESET_DOUT);

  GPIO_PinModeSet(SL_EMLIB_GPIO_INIT_BUTTON_FIRE_PORT,
                  SL_EMLIB_GPIO_INIT_BUTTON_FIRE_PIN,
                  SL_EMLIB_GPIO_INIT_BUTTON_FIRE_MODE,
                  SL_EMLIB_GPIO_INIT_BUTTON_FIRE_DOUT);

  GPIO_PinModeSet(SL_EMLIB_GPIO_INIT_BUTTON_LED_PORT,
                  SL_EMLIB_GPIO_INIT_BUTTON_LED_PIN,
                  SL_EMLIB_GPIO_INIT_BUTTON_LED_MODE,
                  SL_EMLIB_GPIO_INIT_BUTTON_LED_DOUT);
}
