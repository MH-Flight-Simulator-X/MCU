#include "spi.h"
#include "spidrv.h"
#include <stdio.h>
#include <string.h>

SPIDRV_HandleData_t spi_handle_data;
SPIDRV_Handle_t     spi_handle = &spi_handle_data;

void spi_init(void)
{
  SPIDRV_Init_t initData = SPIDRV_MASTER_USART1;
  Ecode_t       ecode = SPIDRV_Init(spi_handle, &initData);
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
  {
    printf("Something went wrong");
  }
}

void spi_transfer(void *buffer, int byte_count)
{

  printf("Sending to slave...\r\n");

  Ecode_t ecode = SPIDRV_MTransmitB(spi_handle, buffer, byte_count);
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
  {
    printf("Something went wrong");
  }
}

// void spi_initialise(void)
// {
//   SPIDRV_Init_t initData = SPIDRV_MASTER_USART1;
//   initData.bitRate = 1000000;
//   SPIDRV_Init(spi_handle, &initData);
// }

// void spi_send_object(airCraft_render_info airCraft)
// {
//   // SegmentLCD_Number();
//   uint8_t buffer = airCraft;

//   SPIDRV_MTransmitB(spi_handle, buffer, sizeof(uint8_t));
// }
