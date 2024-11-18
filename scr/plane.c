#include "controller.h"
#include "plane.h"
#include "debug.h"
#include <math.h>

void aircraft_init(Aircraft *aircraft)
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

void aircraft_check_hit(Aircraft * aircraft, Sprite * sprite)
{
      // Vector from plane to object center
      Vec3 oc = { aircraft->x - sprite->x,
                  aircraft->y - sprite->y,
                  aircraft->z - sprite->z };

      float dx = aircraft->dx, dy = aircraft->dy, dz = aircraft->dz;
      float ox = oc.x, oy = oc.y, oz = oc.z;
      float r = 5.0;

      // Calculate A, B, C for the quadratic equation
      float A = dx * dx + dy * dy + dz * dz;
      float B = 2.0f * (dx * ox + dy * oy + dz * oz);
      float C = ox * ox + oy * oy + oz * oz - r * r;

      // Calculate discriminant
      float discriminant = B * B - 4 * A * C;
      if (discriminant < 0) {
          sprite->live = 1;  // No intersection
      }

      // Calculate both potential solutions for t
      float sqrt_disc = sqrtf(discriminant);
      float t1 = (-B - sqrt_disc) / (2 * A);
      float t2 = (-B + sqrt_disc) / (2 * A);

      // Check for positive t solutions (in the direction of the ray)
      sprite->live = (t1 > 0 || t2 > 0);
}
