#include <aircraft.h>
#include <ai_aircraft.h>
#include "controller.h"
#include "debug.h"
#include <math.h>

void aircraft_init(Aircraft *aircraft)
{
  aircraft->x = aircraft->y = aircraft->z = 0.0f;
  aircraft->roll = aircraft->pitch = aircraft->yaw = 0.0f;
  aircraft->speed = BASE_SPEED;
}

void aircraft_update_pose(Aircraft *aircraft, Controller *controller)
{
  // Adding pitch and roll from joystick to aircraft
  aircraft->roll += controller->roll * 1.5f;
  float pitch = controller->pitch * 0.7f;
  aircraft->pitch -= pitch;

  // Normalizes angles to be between 0° and 360°
  aircraft->roll = normalize_angle(aircraft->roll);
  aircraft->pitch = normalize_angle(aircraft->pitch);

  // Computes gravitational effect based on planes orientation
  float lift = cos_deg(aircraft->roll);
  float gravity_effect = GRAVITY * (1 - lift);

  float vert_pitch = aircraft->pitch * cos_deg(aircraft->roll);
  float hori_pitch = aircraft->pitch * sin_deg(aircraft->roll);

  // Computes target speed based on aircrafts pitch and throttle
  // Precompute the sin for faster computation of sin^3
  float stall_decrease = (STALL_DECREASE * sin_deg(vert_pitch));
  float target_speed = BASE_SPEED * controller->throttle - stall_decrease * stall_decrease * stall_decrease;

  // Ease towards target speed. Further away from target speed accelerates faster
  if (aircraft->speed < target_speed)
    aircraft->speed += (target_speed - aircraft->speed) * 0.01f;
  else
    aircraft->speed -= (aircraft->speed - target_speed) * 0.01f;

  // Compute a heading vector
  float dx = cos_deg(hori_pitch);
  float dy = sin_deg(vert_pitch);
  float dz = sin_deg(hori_pitch);

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

void aircraft_check_hit(Aircraft *a, AiAircraft *opp, int num_aircraft)
{
  // TODO: Implement checks to limit number of sprite comparisons, i.e if position of sprite is behind aircraft
  for (int i = 0; i < num_aircraft; i++)
  {
    AiAircraft ai = opp[i];

    if (ai.status == 1 || ai.status == 2) // Sprite already hit or dead
    {
      continue;
    }

    float dx = a->dx,
          dy = a->dy,
          dz = a->dz; // Decomposed Aircraft heading unit vector

    float ox = a->x - ai.x,
          oy = a->y - ai.y,
          oz = a->z - ai.z; // Decomposed Aircraft-to-Sprite vector

    float r = 5.0; // Radius of Sprite hitbox

    float dot_product = dx * ox + dy * oy + dz * oz;
    if (dot_product <= 0) // Sprite is behind aircraft
    {
      continue;
    }

    // Check if sprite is within rendering distance
    float max_distance_squared = (float)(1 << 20);
    float distance_squared = ox * ox + oy * oy + oz * oz;
    if (distance_squared > max_distance_squared)
    {
      continue;
    }

    // Calculate A, B, C for the quadratic equation
    float A = 1; // Length of heading vector
    float B = 2.0f * dot_product;
    float C = distance_squared - r * r;

    // Calculate discriminant, return if there are no intersections between aircraft heading vector and sprite hitbox
    float discriminant = B * B - 4 * A * C;
    if (discriminant < 0)
    {
      return;
    }

    // Calculate both potential solutions for t
    float sqrt_disc = sqrtf(discriminant);
    float t1 = (-B - sqrt_disc);
    float t2 = (-B + sqrt_disc);

    // Check for positive t solutions (in the direction of the ray)
    if (t1 > 0 || t2 > 0)
    {
      ai.status = 1;
    }
  }
}

void aircraft_check_collision(Aircraft *a, AiAircraft *opp, int num_aircraft)
{

  for (int i = 0; i < num_aircraft; i++)
  {
    AiAircraft ai = opp[i];

    if (ai.status == 1 || ai.status == 2) // Sprite already hit or dead
    {
      continue;
    }

    float dx = a->x - ai.x;
    float dy = a->y - ai.y;
    float dz = a->z - ai.z;

    // Calculate distance squared (avoiding square root for performance)
    float distance_squared = dx * dx + dy * dy + dz * dz;

    // Compare with radius squared (5*5 = 25)
    if (distance_squared <= 25.0f)
    {
      ai.status = 1;
    }
  }
}
