#include "em_gpio.h"
#include "sl_emlib_gpio_init_FPGA_Reset_config.h"


void fpga_reset(){
  GPIO_PinOutClear(SL_EMLIB_GPIO_INIT_FPGA_RESET_PORT, SL_EMLIB_GPIO_INIT_FPGA_RESET_PIN);
  GPIO_PinOutSet(SL_EMLIB_GPIO_INIT_FPGA_RESET_PORT, SL_EMLIB_GPIO_INIT_FPGA_RESET_PIN);
}
