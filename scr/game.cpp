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
#include <string.h>
#include <stdio.h>
#include "../include/cglm/cglm.h"

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif

#ifndef LED_INSTANCE_0
#define LED_INSTANCE_0 sl_led_led0
#endif

#ifndef LED_INSTANCE_1
#define LED_INSTANCE_1 sl_led_led1
#endif

int iteration = 0;
int sprite_count = 10;
Aircraft aircraft;
Controller controller;
Sprite **sprites;
MvpMatrixEntry *matrix_entries;
mat4 **mvp_matrices;
// Can be made into one number where each bit represents an object
uint32_t hits[sprite_count-1];

void game_init()
{
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

  // generate mvp matrix for aircraft/camera
  //    mat4 mvp_matrix;
  //    generate_mvp_matrix((Sprite *)&aircraft, &aircraft, mvp_matrix);

  //    mvp_matrices[0].flag_id = 0x42;
  //    mvp_matrices[0].mvp_matrix = &mvp_matrix;

  //    // generate mvp matrix for rest of the objects
  //    for (int i = 1; i < sprite_count; i++)
  //    {
  //      generate_mvp_matrix(sprites[i - 1], &aircraft, mvp_matrix);
  //      mvp_matrices[i] = &mvp_matrix;
  //    }

  if (frame_counter % 60 == 0)
  {
    // TODO move to happen very frame, this is for debugging
    if (controller.roll > 0)
    {
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

//      matrix_entries[0].flag_id = 0x42;
//      generate_mvp_matrix(&sprite, &aircraft2, matrix_entries[0].mvp_matrix);

      //          mat4 matrix = {
      //              {-0.1134f,  2.3458f,  0.2284f,  0.2279f},
      //              {-0.5306f,  0.4838f, -0.9367f, -0.9349f},
      //              { 1.7274f,  0.3026f, -0.2727f, -0.2722f},
      //              {139.7928f, 247.9165f, 10.0061f, 11.9841f}
      //          };

      //          MvpMatrixEntry matrix_entries[1];
      //          matrix_entries[0].flag_id = 0x42;

      //          memcpy(matrix_entries[0].mvp_matrix, matrix, sizeof(mat4));

//      fpga_frame_send(matrix_entries, 1);
    }
    //    char x[20];
    //    char y[20];
    //    char z[20];
    //    char speed[20];
    //    char pitch[20];
    //    char roll[20];
    //
    //    float_to_string(x, sizeof(x), aircraft.x);
    //    float_to_string(y, sizeof(y), aircraft.y);
    //    float_to_string(z, sizeof(z), aircraft.z);
    //    float_to_string(speed, sizeof(speed), aircraft.speed);
    //    float_to_string(pitch, sizeof(pitch), aircraft.pitch);
    //    float_to_string(roll, sizeof(roll), aircraft.roll);
    //
    //    debug_printf("%s, %s, %s | P: %s | R: %s | S: %s",
    //                 x, y, z, pitch, roll, speed);

    display_print_and_rotate_string();
  }
}
