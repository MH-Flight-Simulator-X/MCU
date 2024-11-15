#include "spi.h"
#include "spidrv.h"
#include "debug.h"
#include "sl_spidrv_instances.h"
#include <stdio.h>
#include <string.h>

#ifndef FPGA_SPI_INSTANCE
#define FPGA_SPI_INSTANCE sl_spidrv_inst_handle
#endif

void spi_init(void)
{
  sl_spidrv_init_instances();
}

void spi_transfer(void *buffer, int byte_count)
{
  Ecode_t ecode = SPIDRV_MTransmitB(FPGA_SPI_INSTANCE, buffer, byte_count);
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
    debug_print("Something went wrong with SPI transfer\n");
}
