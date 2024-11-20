/***************************************************************************//**
 * @file
 * @brief Simple Button Driver Instances
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SL_SIMPLE_BUTTON_INSTANCES_H
#define SL_SIMPLE_BUTTON_INSTANCES_H

#include "sl_simple_button.h"

extern const sl_button_t sl_button_btn0;
extern const sl_button_t sl_button_btn1;
extern const sl_button_t sl_button_fire;

extern const sl_button_t *sl_simple_button_array[];

#define SL_SIMPLE_BUTTON_COUNT 3
#define SL_SIMPLE_BUTTON_INSTANCE(n) (sl_simple_button_array[n])

void sl_simple_button_init_instances(void);
void sl_simple_button_poll_instances(void);

#endif // SL_SIMPLE_BUTTON_INSTANCES_H
