#include <fcntl.h>
#include <getopt.h>
#include <spidrv.h>
#include <segmentlcd.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdint.h>


SPIDRV_HandleData_t spi_handleData;

SPIDRV_Handle_t spi_handle = &spi_handleData;

void spi_initialise(void) {
  SPIDRV_Init_t initData = SPIDRV_MASTER_USART1;
  initData.bitRate = 1000000;
  SPIDRV_Init(spi_handle, &initData);
}

void spi_send_object(airCraft_render_info airCraft) {
  // SegmentLCD_Number();
  uint8_t buffer = airCraft;

  SPIDRV_MTransmitB(spi_handle, buffer, sizeof(uint8_t));
}
