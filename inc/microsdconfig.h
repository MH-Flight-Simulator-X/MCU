/***************************************************************************//**
 * @file
 * @brief Provide MicroSD SPI configuration parameters.
 * @author Energy Micro AS
 * @version 3.20.2
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silicon Labs Software License Agreement. See 
 * "http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt"  
 * for details. Before using this software for any purpose, you must agree to the 
 * terms of that agreement.
 *
 ******************************************************************************/


#ifndef __MICROSDCONFIG_H
#define __MICROSDCONFIG_H

/* Don't increase MICROSD_HI_SPI_FREQ beyond 8MHz. Next step will be 16MHz  */
/* which is out of spec.                                                    */
#define MICROSD_HI_SPI_FREQ     8000000

#define MICROSD_LO_SPI_FREQ     100000
#define MICROSD_USART           USART0
#define MICROSD_LOC             USART_ROUTE_LOCATION_LOC0
#define MICROSD_CMUCLOCK        cmuClock_USART0
#define MICROSD_GPIOPORT        gpioPortE
#define MICROSD_MOSIPIN         10
#define MICROSD_MISOPIN         11
#define MICROSD_CSPIN           13
#define MICROSD_CLKPIN          12

#endif /* __MICROSDCONFIG_H */
