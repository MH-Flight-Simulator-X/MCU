#include "spidrv.h"
#include "spi.h"
#include "app.h"

SPIDRV_HandleData_t spi_handle_data;
SPIDRV_Handle_t spi_handle = &spi_handle_data;

Ecode_t spi_init(void)
{
  SPIDRV_Init_t initData = SPIDRV_MASTER_USART1;
  // initData.frameLength = 16;
  return SPIDRV_Init(spi_handle, &initData);
}

Ecode_t spi_transfer(void *buffer, int byte_count)
{
  return SPIDRV_MTransmitB(spi_handle, buffer, byte_count);
}
