/***************************************************************************//**
 * @file
 * @brief I2C simple poll-based master mode driver instance initialilization
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
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
 ******************************************************************************/

#include "sl_i2cspm.h"
#include "em_cmu.h"
// Include instance config 
#include "sl_i2cspm_display_config.h"

sl_i2cspm_t *sl_i2cspm_display = SL_I2CSPM_DISPLAY_PERIPHERAL;

#if SL_I2CSPM_DISPLAY_SPEED_MODE == 0
#define SL_I2CSPM_DISPLAY_HLR i2cClockHLRStandard
#define SL_I2CSPM_DISPLAY_MAX_FREQ I2C_FREQ_STANDARD_MAX
#elif SL_I2CSPM_DISPLAY_SPEED_MODE == 1
#define SL_I2CSPM_DISPLAY_HLR i2cClockHLRAsymetric
#define SL_I2CSPM_DISPLAY_MAX_FREQ I2C_FREQ_FAST_MAX
#elif SL_I2CSPM_DISPLAY_SPEED_MODE == 2
#define SL_I2CSPM_DISPLAY_HLR i2cClockHLRFast
#define SL_I2CSPM_DISPLAY_MAX_FREQ I2C_FREQ_FASTPLUS_MAX
#endif

I2CSPM_Init_TypeDef init_display = { 
  .port = SL_I2CSPM_DISPLAY_PERIPHERAL,
  .sclPort = SL_I2CSPM_DISPLAY_SCL_PORT,
  .sclPin = SL_I2CSPM_DISPLAY_SCL_PIN,
  .sdaPort = SL_I2CSPM_DISPLAY_SDA_PORT,
  .sdaPin = SL_I2CSPM_DISPLAY_SDA_PIN,
  .portLocation = SL_I2CSPM_DISPLAY_ROUTE_LOC,

  .i2cRefFreq = 0,
  .i2cMaxFreq = SL_I2CSPM_DISPLAY_MAX_FREQ,
  .i2cClhr = SL_I2CSPM_DISPLAY_HLR
};

void sl_i2cspm_init_instances(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);
  I2CSPM_Init(&init_display);
}
