#include "controller.h"
#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "../include/cglm/cglm.h"
#include "plane.h"
#include "game.h"
#include "debug.h"
#include "display.h"
#include "transformation.h"
#include "fpga_spi.h"
#include "spi.h"
#include <string.h>
#include <stdio.h>
#include "../include/cglm/cglm.h"


#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"

#ifndef BUTTON_INSTANCE_0
#define BUTTON_INSTANCE_0 sl_button_btn0
#endif

#ifndef BUTTON_INSTANCE_1
#define BUTTON_INSTANCE_1 sl_button_btn1
#endif

int iteration = 0;
int sprite_count = 10;
Aircraft aircraft;
Controller controller;
Sprite **sprites;
MvpMatrixEntry *matrix_entries;
mat4 **mvp_matrices;
// Can be made into one number where each bit represents an object
//uint32_t hits[sprite_count-1];

void game_init()
{
  spi_init();
  display_init();
  init_aircraft(&aircraft);
  sprites = (Sprite **)malloc((sprite_count - 1) * sizeof(Sprite *));
  matrix_entries = (MvpMatrixEntry *)malloc(sprite_count * sizeof(MvpMatrixEntry));
  controller_init(&controller);
}

void game_process_action(uint32_t frame_counter)
{

  controller_get_inputs(&controller, frame_counter);

  update_aircraft(&aircraft, &controller, frame_counter);

  Aircraft aircraft2;
  aircraft2.x = 10.0f;
  aircraft2.y = 20.0f;
  aircraft2.z = 30.0f;
  aircraft2.roll = 15.0f;
  aircraft2.pitch = 30.0f;
  aircraft2.yaw = 45.0f;
  aircraft2.speed = 100.0f;

  // Initialize Sprite
  Sprite sprite;
  sprite.x = 80.0f;
  sprite.y = 100.123f;
  sprite.z = 15.0f;
  sprite.roll = 70.0f;
  sprite.pitch = 20.0f;
  sprite.yaw = 30.0f;

  matrix_entries[0].flag_id = 0x42;
  generate_mvp_matrix(&sprite, &aircraft2, matrix_entries[0].mvp_matrix);

  fpga_frame_send(matrix_entries, 1);
  if (frame_counter % 60 == 0)
  {
    // TODO move to happen very frame, this is for debugging
    if (controller.roll > 0)
    {
    }
    display_print_and_rotate_string();
  }
}
