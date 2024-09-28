#ifndef SPI_INTERFACE
#define SPI_INTERFACE

#include "spidrv.h"

extern SPIDRV_HandleData_t spi_handle_data;
extern SPIDRV_Handle_t spi_handle;

Ecode_t spi_init(void);

Ecode_t spi_transfer(void *buffer, int byte_count);

#endif // SPI_INTERFACEß