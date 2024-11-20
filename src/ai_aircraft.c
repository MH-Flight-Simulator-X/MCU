#include "ai_aircraft_init.h"
#include "ai_aircraft.h"
#include "aircraft.h"

void ai_aircraft_copy(AiAircraft *dest, const AiAircraft *src, int count)
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
    aircraft[i].id = i + 1;
    accumulate_heading_durations(aircraft[i].headings, aircraft[i].num_headings);
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
        continue;
      }
    Heading *headings = craft->headings;

    int total_duration = headings[craft->num_headings - 1].duration;
    int current_frame = frame_counter % total_duration;
    if (current_frame == 0)
    {
      craft->x = original_aircraft[i].x;
      craft->y = original_aircraft[i].y;
      craft->z = original_aircraft[i].z;
    }

    int heading_index = 0;
    while (heading_index < craft->num_headings && current_frame > headings[heading_index].duration)
    {
      heading_index++;
    }

    Heading current_heading = headings[heading_index];

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
