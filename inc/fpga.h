#define FPGA_H
#define FPGA_SPI_INSTANCE sl_spidrv_inst_handle

#include "transformation.h"
#include <stdint.h>
#include "spidrv.h"

extern SPIDRV_HandleData_t spi_slave_handle_data;
extern SPIDRV_Handle_t spi_slave_handle;

typedef struct
{
  uint8_t flag_id;
  mat4 mvp_matrix;
} MvpMatrixEntry;

void fpga_frame_send(MvpMatrixEntry *entries, uint8_t entry_count, uint32_t frame_counter);
void fpga_reset();
void spi_init(void);
void spi_transfer(void *buffer, int byte_count);
