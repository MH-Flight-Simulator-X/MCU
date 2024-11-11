#ifndef PLANE_H
#define PLANE_H

#include <math.h>

#define BASE_SPEED 100.0f
#define PRECISION 100.0f
#define GRAVITY 10.0f

static inline float deg_to_rad(float degrees) { return degrees * M_PI / 180.0f; }
static inline float rad_to_deg(float radians) { return radians * 180.0f / M_PI; }
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
  float x, y, z;
  float dx, dy, dz;
  float pitch, roll;
  float vert_rotation, hori_rotation;
  float speed;
  float thrust;
} Plane;

void init_plane(Plane *plane);
void update_plane(Plane *plane);

#endif // PLANE_H
