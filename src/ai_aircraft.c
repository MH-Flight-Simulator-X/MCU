/*********************************************************************************************
 * @file ai_aircraft.c
 * @brief Implementation of AI-controlled aircraft movement and behavior systems
 *
 * This file contains the core functionality for managing AI aircraft, including
 * initialization, movement patterns, and status updates. Aircraft follow predefined
 * heading patterns and can move in both forward and reverse directions along these paths.
 *********************************************************************************************/

#include "ai_aircraft_init.h"
#include "ai_aircraft.h"
#include "aircraft.h"

/*********************************************************************************************
 * @brief Copies AI aircraft data from source to destination
 * @param dest Pointer to destination array of AiAircraft
 * @param src Pointer to source array of AiAircraft
 * @param count Number of aircraft to copy
 *********************************************************************************************/
void ai_aircraft_copy(AiAircraft *dest, const AiAircraft *src, int count)
{
  for (int i = 0; i < count; i++)
  {
    dest[i] = src[i];
  }
}

/*********************************************************************************************
 * @brief Normalizes a 3D vector to unit length
 * @param dx Pointer to x component
 * @param dy Pointer to y component
 * @param dz Pointer to z component
 *********************************************************************************************/
void normalize_vector(float *dx, float *dy, float *dz)
{
  float length = sqrt((*dx) * (*dx) + (*dy) * (*dy) + (*dz) * (*dz));
  if (length > 0)
  {
    *dx /= length;
    *dy /= length;
    *dz /= length;
  }
}

/*********************************************************************************************
 * @brief Converts heading durations to cumulative values
 * @param headings Array of Heading structures
 * @param num_headings Number of headings in the array
 * 
 * Each heading's duration becomes the sum of its own duration plus all previous durations.
 *********************************************************************************************/
void accumulate_heading_durations(Heading *headings, int num_headings)
{
  for (int i = 1; i < num_headings; i++)
  {
    headings[i].duration += headings[i - 1].duration;
  }
}

/*********************************************************************************************
 * @brief Initializes an array of AI aircraft
 * @param aircraft Array of AiAircraft structures to initialize
 * @param num_aircraft Number of aircraft to initialize
 *
 * Performs the following initialization steps:
 * 1. Assigns unique IDs to each aircraft
 * 2. Accumulates heading durations
 * 3. Normalizes heading vectors
 *********************************************************************************************/
void ai_aircraft_init(AiAircraft *aircraft, int num_aircraft)
{
  for (int i = 0; i < num_aircraft; i++)
  {
    // Give unique ID
    aircraft[i].id = i + 1;

    // Durations are added to be accumulative
    accumulate_heading_durations(aircraft[i].headings, aircraft[i].num_headings);

    // Each vector is normalized to unitvector
    for (int j = 0; j < aircraft[i].num_headings; j++)
    {
      normalize_vector(&(aircraft[i].headings[j].dx),
                       &(aircraft[i].headings[j].dy),
                       &(aircraft[i].headings[j].dz));
    }
  }
}

/*********************************************************************************************
 * @brief Updates the position and orientation of AI aircraft
 * @param aircraft Array of AiAircraft structures
 * @param num_aircraft Number of aircraft to update
 * @param frame_counter Current frame number for timing
 *
 * Updates aircraft positions based on their heading patterns. Aircraft follow their
 * paths forward, then reverse direction and return along the same path.
 * Dead aircraft (status == 2) are skipped.
 *********************************************************************************************/
void ai_aircraft_update_pose(AiAircraft *aircraft, int num_aircraft, int frame_counter)
{
  for (int i = 0; i < num_aircraft; i++)
  {
    AiAircraft *craft = &aircraft[i];
    if (craft->status == 2)
    {
    // Aircraft is dead
      continue;
    }
    Heading *headings = craft->headings;

    // Total duration is the last heading (because of cumulative duration)
    // Mulitplied by 2 since we move backwards on the same headings
    int total_duration = headings[craft->num_headings - 1].duration * 2;
    int current_frame = frame_counter % total_duration;

    // Reset the position each turnaround to ensure not moving
    if (current_frame == 0)
    {
      craft->x = original_aircraft[i].x;
      craft->y = original_aircraft[i].y;
      craft->z = original_aircraft[i].z;
    }

    bool reverse = current_frame >= total_duration / 2;
    if (reverse)
    {
      current_frame = total_duration - current_frame;
    }

    int heading_index = 0;
    while (heading_index < craft->num_headings && current_frame > headings[heading_index].duration)
    {
      heading_index++;
    }

    Heading current_heading = headings[heading_index];

    if (reverse)
    {
      // Negate the direction for reverse motion
      current_heading.dx = -current_heading.dx;
      current_heading.dy = -current_heading.dy;
      current_heading.dz = -current_heading.dz;
    }

    ai_aircraft_move(craft, current_heading);
  }
}

/*********************************************************************************************
 * @brief Moves an aircraft according to its current heading
 * @param aircraft Pointer to AiAircraft structure
 * @param heading Current heading to follow
 *
 * Updates aircraft position and orientation (yaw, pitch, roll) based on the
 * provided heading vector. Movement speed is controlled by AI_SPEED/PRECISION.
 *********************************************************************************************/
void ai_aircraft_move(AiAircraft *aircraft, Heading heading)
{
  float dx = heading.dx;
  float dy = heading.dy;
  float dz = heading.dz;

  aircraft->yaw = atan2(dz, dx) * (180.0 / PI);

  float horizontal_length = sqrt(dx * dx + dz * dz);
  aircraft->pitch = atan2(dy, horizontal_length) * (180.0 / PI);

  aircraft->roll = 0.0;

  aircraft->x += dx * AI_SPEED / PRECISION;
  aircraft->y += dy * AI_SPEED / PRECISION;
  aircraft->z += dz * AI_SPEED / PRECISION;
}

/*********************************************************************************************
 * @brief Updates the status of AI aircraft
 * @param aircraft Array of AiAircraft structures
 * @param num_aircraft Number of aircraft to update
 *
 * Manages aircraft status changes:
 * - status 2: Aircraft is dead (set after counter reaches 30)
 * - status alternates between 0 and 1 every 5 frames while counter is active
 *********************************************************************************************/
void ai_aircraft_update_status(AiAircraft *aircraft, int num_aircraft)
{
  for (int i = 0; i < num_aircraft; i++)
  {
    AiAircraft craft = aircraft[i];
    if (!craft.counter)
    {
      continue;
    }
    if (craft.counter == 30)
    {
      craft.status = 2;
      craft.counter = 0;
      continue;
    }
    craft.status = craft.counter % 5 == 0;
    craft.counter++;
  }
}
