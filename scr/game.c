#include "../include/cglm/cglm.h"
#include <string.h>
#include <stdio.h>
#include "aircraft.h"
#include "ai_aircraft.h"
#include "ai_aircraft_init.h"
#include "controller.h"
#include "game.h"
#include "debug.h"
#include "display.h"
#include "transformation.h"
#include "spi.h"
#include "fpga_spi.h"
#include "fpga.h"

int iteration = 0;
int sprite_count = 10;
Aircraft aircraft;
Controller controller;
AiAircraft *ai_aircrafts;
MvpMatrixEntry *matrix_entries;
mat4 **mvp_matrices;
// Can be made into one number where each bit represents an object
// uint32_t hits[sprite_count-1];

void game_init()
{
  spi_init();
  display_init(&aircraft);
  aircraft_init(&aircraft);
  controller_init(&controller);

  ai_aircrafts = (AiAircraft *)malloc(num_aircrafts * sizeof(AiAircraft));
  ai_aircrafts_create(ai_aircrafts, original_aircrafts, num_aircrafts);
  ai_aircrafts_init(ai_aircrafts, num_aircrafts);

  matrix_entries = (MvpMatrixEntry *)malloc(sprite_count * sizeof(MvpMatrixEntry));
  debug_printf("Game initialized");
}

void game_process_action(uint32_t frame_counter)
{
  if (controller->fire)
  {
    controller->fire = 0;
    aircraft_check_hit(&aircraft, &sprites);
  }
  // aircraft_check_collision();
  sprite_update_alive_counter(sprites);

  controller_get_inputs(&controller, frame_counter);

  update_aircraft(&aircraft, &controller, frame_counter);

  ai_aircrafts_update(ai_aircrafts, num_aircrafts, frame_counter);

  matrix_entries[0].flag_id = 0x42;
  generate_mvp_matrix((Sprite *)&aircraft, &aircraft, matrix_entries[0].mvp_matrix);

  for (int i = 0; i < num_aircrafts; i++)
  {
    matrix_entries[i + 1].flag_id = 0x01;
    generate_mvp_matrix((Sprite *)&ai_aircrafts[i], &aircraft, matrix_entries[i + 1].mvp_matrix);
  }

  // calculate if any collisions (set aircraft live bit to 0 --> FPGA can check it and display game over text)
  // calculate any hits (set sprite live bit to 0 --> FPGA may render effects)
  // if all Sprite live bits are 0 FPGA can display win effect

  fpga_frame_send(matrix_entries, 1);
  if (frame_counter % 30 == 0)
  {
    display_print_and_rotate_string();
  }
}
