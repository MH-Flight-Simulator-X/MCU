#include "controller.h"
#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "../include/cglm/cglm.h"
#include "plane.h"
#include "game.h"
#include "display.h"
#include "transformation.h"

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
Aircraft *aircraft;
Controller controller;
Sprite **sprites;
mat4 **mvp_matrices;

void game_init()
{
  display_init();
  aircraft = (Aircraft *)malloc(sizeof(Aircraft));
  init_aircraft(aircraft);
  sprites = (Sprite **)malloc((sprite_count - 1) * sizeof(Sprite *));
  mvp_matrices = (mat4 **)malloc(sprite_count * sizeof(mat4 *));
  controller_init(&controller);
}

void game_process_action(uint32_t frame_counter)
{

  controller_get_inputs(&controller);

  if (controller.pitch > 0)
  {
    sl_led_turn_on(&LED_INSTANCE_0);
  }
  else
  {
    sl_led_turn_off(&LED_INSTANCE_0);
  }
  if (controller.roll > 0)
  {
    sl_led_turn_on(&LED_INSTANCE_1);
  }
  else
  {
    sl_led_turn_off(&LED_INSTANCE_1);
  }

  update_aircraft(aircraft, &controller);

  // generate mvp matrix for aircraft/camera
  mat4 mvp_matrix;
  generate_mvp_matrix((Sprite *)aircraft, aircraft, mvp_matrix);
  mvp_matrices[0] = &mvp_matrix;

  // generate mvp matrix for rest of the objects
  for (int i = 1; i < sprite_count; i++)
  {
    generate_mvp_matrix(sprites[i - 1], aircraft, mvp_matrix);
    mvp_matrices[i] = &mvp_matrix;
  }

  if (frame_counter % 30 == 0)
  {

    display_print_and_rotate_string();
  }
}
