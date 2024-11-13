#include "spi.h"
#include "spidrv.h"
#include <string.h>
#include "sl_simple_led_instances.h"

SPIDRV_HandleData_t spi_handle_data;
SPIDRV_Handle_t     spi_handle = &spi_handle_data;

void spi_init(void)
{
  SPIDRV_Init_t initData = SPIDRV_MASTER_USART0;
  Ecode_t       ecode = SPIDRV_Init(spi_handle, &initData);
//  GPIO_PinModeSet(gpioPortE, 7, gpioModePushPull, 1);

  if (ecode != ECODE_EMDRV_SPIDRV_OK)
  {
    printf("Something went wrong");
  }
}

void spi_transfer(void *buffer, int byte_count)
{
  Ecode_t ecode = SPIDRV_MTransmitB(spi_handle, buffer, byte_count);
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
  {
    printf("Something went wrong");
  }
}
