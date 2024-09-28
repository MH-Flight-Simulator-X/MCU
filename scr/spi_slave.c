#include "spidrv.h"
#include "spi.h"
#include "app.h"

SPIDRV_HandleData_t spi_slave_handle_data;
SPIDRV_Handle_t spi_slave_handle = &spi_slave_handle_data;

Ecode_t spi_slave_init(void)
{
  SPIDRV_Init_t initData = SPIDRV_SLAVE_USART1;
  return SPIDRV_Init(spi_slave_handle, &initData);
}

Ecode_t spi_slave_receive(void *buffer, int byte_count)
{
  return SPIDRV_SReceiveB(spi_slave_handle, buffer, byte_count, 0);
}
