#ifndef SPI_SLAVE_INTERFACE
#define SPI_SLAVE_INTERFACE

#include "spidrv.h"

extern SPIDRV_HandleData_t spi_slave_handle_data;
extern SPIDRV_Handle_t spi_slave_handle;

Ecode_t spi_slave_init(void);

Ecode_t spi_slave_recieve(void *buffer, int byte_count);

#endif // SPI_SLAVE_INTERFACE