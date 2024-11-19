#include "ai_aircraft_init.h"
#include "ai_aircraft.h"
#include "aircraft.h"

void ai_aircraft_create(AiAircraft *dest, const AiAircraft *src, int count)
{
  for (int i = 0; i < count; i++)
  {
    dest[i] = src[i];
  }
}

void normalize_vector(double *dx, double *dy, double *dz)
{
  double length = sqrt((*dx) * (*dx) + (*dy) * (*dy) + (*dz) * (*dz));
  if (length > 0)
  {
    *dx /= length;
    *dy /= length;
    *dz /= length;
  }
}

void accumulate_heading_durations(Heading *headings, int num_headings)
{
  for (int i = 1; i < num_headings; i++)
  {
    headings[i].duration += headings[i - 1].duration;
  }
}

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


void ai_aircraft_move(AiAircraft *aircraft, Heading heading)
{
  double dx = heading.dx;
  double dy = heading.dy;
  double dz = heading.dz;

  aircraft->yaw = atan2(dz, dx) * (180.0 / PI);

  double horizontal_length = sqrt(dx * dx + dz * dz);
  aircraft->pitch = atan2(dy, horizontal_length) * (180.0 / PI);

  aircraft->roll = 0.0;

  aircraft->x += dx * AI_SPEED / PRECISION;
  aircraft->y += dy * AI_SPEED / PRECISION;
  aircraft->z += dz * AI_SPEED / PRECISION;
}

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
