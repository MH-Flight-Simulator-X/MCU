/*****************************************************************************
 * @file sl_sdc_platform_spi_config.h
 * @brief Platform SPI Driver Configuration
 *******************************************************************************
 * # License
 * <b>Copyright 2022 Silicon Laboratories Inc. www.silabs.com</b>
 ********************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided \'as-is\', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 *******************************************************************************
 * # Evaluation Quality
 * This code has been minimally tested to ensure that it builds and is suitable
 * as a demonstration for evaluation purposes only. This code will be maintained
 * at the sole discretion of Silicon Labs.
 ******************************************************************************/
#ifndef SL_SDC_PLATFORM_SPI_CONFIG_H
#define SL_SDC_PLATFORM_SPI_CONFIG_H

#include "em_gpio.h"
#include "em_usart.h"
#include "sl_spidrv_instances.h"

// SPI handle for SD card
#define sdc_spi_handle sl_spidrv_mikroe_handle

// Define the SPI peripheral to use USART1 for EFM32GG990F1024
#define SD_CARD_MMC_PERIPHERAL USART1
#define SD_CARD_MMC_PERIPHERAL_NO 1

// SPI RX port and pin definitions for USART1 on EFM32GG990F1024
#define SD_CARD_MMC_RX_PORT gpioPortC
#define SD_CARD_MMC_RX_PIN 1

// Set slow clock for card initialization (100k-400k)
#define SD_CARD_MMC_SLOW_CLOCK 200000
// Set fast clock for generic read/write operations on SD card
#define SD_CARD_MMC_FAST_CLOCK 1000000

// Chip select (CS) pin configuration for SD card
#define SD_CARD_MMC_CS_PORT gpioPortC
#define SD_CARD_MMC_CS_PIN 3

// Card detection pin configuration on port B, pin 0
#define SD_CARD_MMC_CD_PORT gpioPortB
#define SD_CARD_MMC_CD_PIN 0

#endif /* SL_SDC_PLATFORM_SPI_CONFIG_H */
