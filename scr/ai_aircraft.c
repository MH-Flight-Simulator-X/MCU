#include "ai_aircraft_init.h"
#include "ai_aircraft.h"
#include "aircraft.h"

void ai_aircrafts_create(AiAircraft *dest, const AiAircraft *src, int count)
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

void ai_aircrafts_init(AiAircraft *aircrafts, int num_aircrafts)
{
  for (int i = 0; i < num_aircrafts; i++)
  {
    accumulate_heading_durations(aircrafts[i].headings, aircrafts[i].num_headings);
    for (int j = 0; j < aircrafts[i].num_headings; j++)
    {
      normalize_vector(&(aircrafts[i].headings[j].dx),
                       &(aircrafts[i].headings[j].dy),
                       &(aircrafts[i].headings[j].dz));
    }
  }
}

void ai_aircrafts_update(AiAircraft *aircrafts, int num_aircraft, int frame_counter)
{
  for (int i = 0; i < num_aircraft; i++)
  {
    AiAircraft *aircraft = &aircrafts[i];
    Heading *headings = aircraft->headings;

    int total_duration = headings[aircraft->num_headings - 1].duration;
    int current_frame = frame_counter % total_duration;
    if (current_frame == 0)
    {
      aircraft->x = original_aircrafts[i].x;
      aircraft->y = original_aircrafts[i].y;
      aircraft->z = original_aircrafts[i].z;
    }

    int heading_index = 0;
    while (heading_index < aircraft->num_headings && current_frame > headings[heading_index].duration)
    {
      heading_index++;
    }

    Heading current_heading = headings[heading_index];

    ai_aircraft_move(aircraft, current_heading);
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

void ai_aircraft_update_status(AiAircraft * crafts, int num_aircrafts)
{
  for (int i = 0; i < num_aircrafts; i++)
  {
    AiAircraft a = crafts[i];
    if (a.counter == 30)
    {
      a.status = 2;
    }
    if (a.status == 1)
    {
      a.counter++;
    }
  }
}

