#include "spi.h"
#include "spidrv.h"
#include "debug.h"
#include <stdio.h>
#include <string.h>

SPIDRV_HandleData_t spi_handle_data;
SPIDRV_Handle_t     spi_handle = &spi_handle_data;

void spi_init(void)
{
  SPIDRV_Init_t initData = SPIDRV_MASTER_USART0;
  Ecode_t       ecode = SPIDRV_Init(spi_handle, &initData);
  GPIO_PinModeSet(gpioPortE, 13, gpioModePushPull, 1);
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
    debug_print("Something went wrong with SPI initialization\n");
  else
    debug_print("Spi initialized\n");
}

void spi_transfer(void *buffer, int byte_count)
{
  GPIO_PinOutClear(gpioPortE, 13);
  Ecode_t ecode = SPIDRV_MTransmitB(spi_handle, buffer, byte_count);
  debug_printf("Tester %d\n", GPIO_PinInGet(gpioPortE, 13));
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
    debug_print("Something went wrong with SPI transfer\n");
  GPIO_PinOutSet(gpioPortE, 13);
  debug_printf("Tester %d\n", GPIO_PinInGet(gpioPortE, 13));
}
