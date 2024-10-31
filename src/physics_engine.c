#include "sl_iostream_init_instances.h"
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
#include "sl_sleeptimer.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
  int x;
  int y;
  int z;

  int dx;
  int dy;
  int dz;

  int hp;

} object_t;

typedef struct
{
  int amplitude;
  int x;
  int y;
  int z;
} force_t;

void apply_force(object_t *object, force_t *force)
{
  object->dx += force->x;
  object->dy += force->y;
  object->dz += force->z;
}

void run(void)
{

  // Get data from thumbstick and slider I/O
}
