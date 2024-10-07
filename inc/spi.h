#include <spidrv.h>
#include <unistd.h>

struct airCraft_render_info
{
  uint16_t x;
  uint16_t y;
  uint16_t z;

} typedef airCraft_render_info;

void spi_initialise(void);
void spi_send_object(airCraft_render_info airCraft);

void spi_load_game_from_sd(void);
