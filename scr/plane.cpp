#include "controller.h"
#include "plane.h"
#include "debug.h"
#include <math.h>

void init_aircraft(Aircraft *aircraft)
{
  aircraft->x = aircraft->y = aircraft->z = 145.0f;
  aircraft->roll = aircraft->pitch = aircraft->yaw = 60.0f;
  aircraft->speed = BASE_SPEED;
}

void update_aircraft(Aircraft *aircraft, Controller *controller, uint32_t frame_counter)
{
  // Adding pitch and roll from joystick to aircraft
  aircraft->roll += controller->roll * 1.5f;
  float pitch = controller->pitch * cos_deg(aircraft->roll) * 0.7f;
  float yaw = controller->pitch * sin_deg(aircraft->roll) * 0.7f;
  aircraft->pitch += pitch;
  aircraft->yaw += yaw;

  // Normalizes angles to be between 0° and 360°
  aircraft->roll = normalize_angle(aircraft->roll);
  aircraft->pitch = normalize_angle(aircraft->pitch);
  aircraft->yaw = normalize_angle(aircraft->yaw);

  // Computes gravitational effect based on planes orientation
  float lift = cos_deg(aircraft->roll);
  float gravity_effect = GRAVITY * (1 - lift);


  // Computes target speed based on aircrafts pitch and throttle
  // Precompute the sin for faster computation of sin^3
  float stall_decrease = (STALL_DECREASE * sin_deg(aircraft->pitch));
  float target_speed = BASE_SPEED * controller->throttle - stall_decrease*stall_decrease*stall_decrease;


  // Ease towards target speed. Further away from target speed accelerates faster
  if (aircraft->speed < target_speed)
    aircraft->speed += (target_speed - aircraft->speed) * 0.01f;
  else
    aircraft->speed -= (aircraft->speed - target_speed) * 0.01f;

  // Compute a heading vector
  float dx = cos_deg(aircraft->yaw);
  float dy = sin_deg(aircraft->pitch);
  float dz = sin_deg(aircraft->yaw);

  // Normalize the heading vector
  float length = sqrt(dx * dx + dy * dy + dz * dz);
  dx /= length;
  dy /= length;
  dz /= length;

  // Update position based on heading and speed
  aircraft->x += dx * aircraft->speed / PRECISION;
  aircraft->y += (dy * aircraft->speed - gravity_effect) / PRECISION;
  aircraft->z += dz * aircraft->speed / PRECISION;
}
