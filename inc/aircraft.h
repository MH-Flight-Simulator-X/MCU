#ifndef PLANE_H
#define PLANE_H

#include <math.h>

#include "controller.h"

#define BASE_SPEED 100.0f
#define PRECISION 500.0f
#define GRAVITY 0.0f
#define STALL_DECREASE 5.0f
#define PI 3.1415926535f

static inline float deg_to_rad(float degrees) { return degrees * PI / 180.0f; }
static inline float rad_to_deg(float radians) { return radians * 180.0f / PI; }
static inline float cos_deg(float degrees) { return cos(deg_to_rad(degrees)); }
static inline float sin_deg(float degrees) { return sin(deg_to_rad(degrees)); }

static inline float normalize_angle(float angle)
{
  while (angle < 0)
    angle += 360.0f;
  while (angle >= 360)
    angle -= 360.0f;
  return angle;
}

typedef struct
{
  double x, y, z;
  double dx, dy, dz;
  double roll, pitch, yaw;
  double dy, dx, dz;
  double speed;
} Aircraft;

typedef struct {
    double x, y, z;
} Vec3;

typedef struct
{
  double x, y, z;
  double roll, pitch, yaw;
  uint32_t counter, status;
} Sprite;

void aircraft_init(Aircraft *plane);
void update_aircraft(Aircraft *plane, Controller *controller, uint32_t frame_counter);
void aircraft_check_hit(Aircraft * aircraft, Sprite * sprite);
void sprite_update_status(Sprite ** sprite);



#endif // PLANE_H
