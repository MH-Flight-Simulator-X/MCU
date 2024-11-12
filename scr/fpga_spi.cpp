#include "fpga_spi.h"
#include "transformation.h"
#include "fixedpoint.h"
#include "spi.h"
#include <string.h>

void convert_float_to_fixedpoint_bytes(float value, uint8_t *buffer)
{
  fp fixed_value = fl2fp(value);
  buffer[0] = (fixed_value >> 16) & 0xFF;
  buffer[1] = (fixed_value >> 8) & 0xFF;
  buffer[2] = fixed_value & 0xFF;
}

void fpga_frame_send(MvpMatrixEntry *entries, uint8_t entry_count)
{
  const int entry_size = 1 + 16 * 3;
  const int total_size = 1 + entry_count * entry_size;

  uint8_t buffer[total_size];
  memset(buffer, 0, total_size);

  buffer[0] = entry_count;

  for (uint8_t i = 0; i < entry_count; i++)
  {
    int offset = 1 + i * entry_size;
    buffer[offset] = entries[i].flag_id;
    offset += 1;

    for (int j = 0; j < 16; j++)
    {
      convert_float_to_fixedpoint_bytes(entries[i].mvp_matrix[j / 4][j % 4], &buffer[offset]);
      offset += 3;
    }
  }

  spi_transfer(buffer, total_size);
}
