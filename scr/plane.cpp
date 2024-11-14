#include <controller.h>
#include "plane.h"
#include "adc_reader.h"
#include <math.h>

void init_aircraft(Aircraft *aircraft)
{
  aircraft->x = aircraft->y = aircraft->z = 0.0f;
  aircraft->dx = 1.0f;
  aircraft->dy = aircraft->dz = 0.0f;
  aircraft->pitch_vertical = aircraft->pitch_horizontal = aircraft->roll = 0.0f;
  aircraft->speed = BASE_SPEED;

  //exprimental 
  aircraft->pitch = 0;
  aircraft->yaw = 0;
}

void update_aircraft(Aircraft *aircraft, Controller *controller)
{
  aircraft->roll += controller->roll * 1.5f;

  float lift = cos_deg(aircraft->roll);
  float gravity_effect = GRAVITY * (1 - lift);


  aircraft->roll = normalize_angle(aircraft->roll);
  float pitch_vertical = controller->pitch * cos_deg(aircraft->roll) * 0.3f;
  float pitch_horizontal = controller->pitch * sin_deg(aircraft->roll) * 0.3f;
  aircraft->pitch_vertical += pitch_vertical;
  aircraft->pitch_horizontal += pitch_horizontal;

  aircraft->pitch_vertical = normalize_angle(aircraft->pitch_vertical);
  aircraft->pitch_horizontal = normalize_angle(aircraft->pitch_horizontal);

  // Precompute the sin for faster computation of sin^3
  float stall_decrease = (STALL_DECREASE * sin_deg(aircraft->pitch_vertical));
  float target_speed = BASE_SPEED * controller->throttle - stall_decrease*stall_decrease*stall_decrease*sqrt(aircraft->speed);


  if (aircraft->speed < target_speed)
    aircraft->speed += (target_speed - aircraft->speed) * 0.05f;
  else
    aircraft->speed -= (aircraft->speed - target_speed) * 0.05f;

  aircraft->dx = cos_deg(aircraft->pitch_horizontal);
  aircraft->dy = sin_deg(aircraft->pitch_vertical);
  aircraft->dz = sin_deg(aircraft->pitch_horizontal);

  // Normalize the heading vector
  float length = sqrt(aircraft->dx * aircraft->dx + aircraft->dy * aircraft->dy + aircraft->dz * aircraft->dz);
  aircraft->dx /= length;
  aircraft->dy /= length;
  aircraft->dz /= length;

  // Update position based on heading and speed
  aircraft->x += aircraft->dx * aircraft->speed / PRECISION;
  aircraft->y += (aircraft->dy * aircraft->speed - gravity_effect) / PRECISION;
  aircraft->z += aircraft->dz * aircraft->speed / PRECISION;

  // Exprimental
  aircraft->pitch = asin(-aircraft->dy);
  aircraft->yaw = atan2(aircraft->dx, aircraft->dz);
}
