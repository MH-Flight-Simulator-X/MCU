#include "spi.h"
#include "spidrv.h"
#include "debug.h"
#include <stdio.h>
#include <string.h>

SPIDRV_HandleData_t spi_handle_data;
SPIDRV_Handle_t     spi_handle = &spi_handle_data;

void spi_init(void)
{
  SPIDRV_Init_t initData = SPIDRV_MASTER_USART1;
  Ecode_t       ecode = SPIDRV_Init(spi_handle, &initData);
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
    debug_print("Something went wrong with SPI initialization");
  else
    debug_print("Spi initialized");
}

void spi_transfer(void *buffer, int byte_count)
{
  Ecode_t ecode = SPIDRV_MTransmitB(spi_handle, buffer, byte_count);
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
    debug_print("Something went wrong with SPI transfer");
}
