#include "plane.h"

int main()
{
  Plane plane;
  init_plane(&plane);
  while (1)
  {
    handle_input(&plane);
    update_plane(&plane);
  }

  return 0;
}

void init_plane(Plane *plane)
{
  plane->x = plane->y = plane->z = 0.0;
  plane->dx = 1.0;
  plane->dy = plane->dz = 0.0;
  plane->pitch = plane->roll = 0.0;
  plane->vert_rotation = plane->hori_rotation = 0.0;
  plane->speed = BASE_SPEED;
  plane->thrust = 0.5;
}

void update_plane(Plane *plane)
{
  float lift = cos_deg(plane->roll);
  float gravity_effect = GRAVITY * (1 - lift);

  float target_speed = BASE_SPEED * plane->thrust - 50.0 * sin_deg(plane->vert_rotation);
  if (plane->speed < target_speed)
    plane->speed += (target_speed - plane->speed) * 0.05;
  else
    plane->speed -= (plane->speed - target_speed) * 0.05;

  plane->roll = normalize_angle(plane->roll);
  float pitch_vertical = plane->pitch * cos_deg(plane->roll) * 0.1;
  float pitch_horizontal = plane->pitch * sin_deg(plane->roll) * 0.1;
  plane->vert_rotation += pitch_vertical;
  plane->hori_rotation += pitch_horizontal;

  plane->vert_rotation = normalize_angle(plane->vert_rotation);
  plane->hori_rotation = normalize_angle(plane->hori_rotation);

  if (plane->vert_rotation > 0 && plane->vert_rotation < 90)
  {
    float gravity_pitch_down = GRAVITY * (1.0 - plane->speed / BASE_SPEED) * sin_deg(plane->vert_rotation);
    plane->vert_rotation -= gravity_pitch_down;
  }
  plane->vert_rotation = normalize_angle(plane->vert_rotation);

  plane->dx = cos_deg(plane->hori_rotation);
  plane->dy = sin_deg(plane->vert_rotation);
  plane->dz = sin_deg(plane->hori_rotation);

  float length = sqrt(plane->dx * plane->dx + plane->dy * plane->dy + plane->dz * plane->dz);
  plane->dx /= length;
  plane->dy /= length;
  plane->dz /= length;

  plane->x += plane->dx * plane->speed / PRECISION;
  plane->y += (plane->dy * plane->speed - gravity_effect) / PRECISION;
  plane->z += plane->dz * plane->speed / PRECISION;
}
