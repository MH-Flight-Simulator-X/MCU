#include "spi.h"
#include "spidrv.h"
#include "debug.h"
#include "sl_spidrv_instances.h"
#include <stdio.h>
#include <string.h>

/*********************************************************************************************
 * @file spi.c
 * @brief SPI communication implementation for FPGA interface
 *
 * This module provides basic SPI (Serial Peripheral Interface) communication 
 * functionality for interfacing with an FPGA. It uses the Silicon Labs SPIDRV 
 * driver for handling the low-level SPI communications.
 *********************************************************************************************/

#ifndef FPGA_SPI_INSTANCE
#define FPGA_SPI_INSTANCE sl_spidrv_inst_handle
#endif

/*********************************************************************************************
 * @brief Initializes the SPI interface
 * 
 * Initializes all SPI driver instances using the Silicon Labs SPIDRV 
 * initialization function. This must be called before any SPI transfers 
 * can occur.
 *********************************************************************************************/
void spi_init(void)
{
  sl_spidrv_init_instances();
}

/*********************************************************************************************
 * @brief Performs a blocking SPI transfer
 * 
 * @param buffer      Pointer to the data buffer to transmit
 * @param byte_count  Number of bytes to transfer
 * 
 * @note This function performs a blocking transmit operation. If the transfer
 *       fails, a debug message will be printed.
 * 
 * @warning The buffer must be valid and contain at least byte_count bytes
 *********************************************************************************************/
void spi_transfer(void *buffer, int byte_count)
{
  Ecode_t ecode = SPIDRV_MTransmitB(FPGA_SPI_INSTANCE, buffer, byte_count);
  if (ecode != ECODE_EMDRV_SPIDRV_OK)
    debug_print("Something went wrong with SPI transfer\n");
}


