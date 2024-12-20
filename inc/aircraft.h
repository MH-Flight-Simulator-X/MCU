#ifndef PLANE_H
#define PLANE_H

#include <math.h>
#include <ai_aircraft.h>

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
  while (angle < -180.0f)
    angle += 360.0f;
  while (angle >= 180)
    angle -= 360.0f;
  return angle;
}

typedef struct
{
  float x, y, z;
  float dx, dy, dz;
  float pitch, yaw, roll;
  float speed;
  int id;
} Aircraft;

typedef struct
{
  float x, y, z;
} Vec3;

typedef struct
{
  float x, y, z;
  float pitch, yaw, roll;
  uint32_t counter, status;
} Sprite;

void aircraft_init(Aircraft *plane);
void aircraft_check_hit(Aircraft *a, AiAircraft *opp, int num_aircrafts);
void aircraft_check_collision(Aircraft *a, AiAircraft *opp, int num_aircraft);
void aircraft_update_pose(Aircraft *plane, Controller *controller);

#endif // PLANE_H
