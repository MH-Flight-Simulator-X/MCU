#include "plane.h"
#include "adc_reader.h"

void init_plane(Plane *plane)
{
  plane->x = plane->y = plane->z = 0.0f;
  plane->dx = 1.0f;
  plane->dy = plane->dz = 0.0f;
  plane->pitch_vertical = plane->pitch_horizontal = plane->roll = 0.0f;
  plane->speed = BASE_SPEED;
}

void update_plane(Plane *plane, Controller *controller)
{
  plane->roll += controller->roll * 1.5f;

  float lift = cos_deg(plane->roll);
  float gravity_effect = GRAVITY * (1 - lift);


  plane->roll = normalize_angle(plane->roll);
  float pitch_vertical = controller->pitch * cos_deg(plane->roll) * 0.3f;
  float pitch_horizontal = controller->pitch * sin_deg(plane->roll) * 0.3f;
  plane->pitch_vertical += pitch_vertical;
  plane->pitch_horizontal += pitch_horizontal;

  plane->pitch_vertical = normalize_angle(plane->pitch_vertical);
  plane->pitch_horizontal = normalize_angle(plane->pitch_horizontal);

  // Precompute the sin for faster computation of sin^3
  float stall_decrease = (STALL_DECREASE * sin_deg(plane->pitch_vertical));
  float target_speed = BASE_SPEED * controller->throttle - stall_decrease*stall_decrease*stall_decrease*sqrt(plane->speed);


  if (plane->speed < target_speed)
    plane->speed += (target_speed - plane->speed) * 0.05f;
  else
    plane->speed -= (plane->speed - target_speed) * 0.05f;

  plane->dx = cos_deg(plane->pitch_horizontal);
  plane->dy = sin_deg(plane->pitch_vertical);
  plane->dz = sin_deg(plane->pitch_horizontal);

  // Normalize the heading vector
  float length = sqrt(plane->dx * plane->dx + plane->dy * plane->dy + plane->dz * plane->dz);
  plane->dx /= length;
  plane->dy /= length;
  plane->dz /= length;

  // Update position based on heading and speed
  plane->x += plane->dx * plane->speed / PRECISION;
  plane->y += (plane->dy * plane->speed - gravity_effect) / PRECISION;
  plane->z += plane->dz * plane->speed / PRECISION;
}
