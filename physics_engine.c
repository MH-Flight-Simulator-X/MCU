#include <stdio.h>
#include <string.h>
#include "sleeptimer_app.h"
#include "sl_sleeptimer.h"
#include "sl_simple_led_instances.h"
#include "sl_simple_button_instances.h"
#include "sl_iostream_init_instances.h"

typedef struct
{
    _Float16 x;
    _Float16 y;
    _Float16 z;

    _Float16 dx;
    _Float16 dy;
    _Float16 dz;

    int hp;

} object_t;

typedef struct
{
    _Float16 amplitude;
    _Float16 x;
    _Float16 y;
    _Float16 z;
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
