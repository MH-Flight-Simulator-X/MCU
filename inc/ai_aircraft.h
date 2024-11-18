#ifndef AI_AIRCRAFT_H
#define AI_AIRCRAFT_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define AI_SPEED 80

typedef struct
{
  double dx, dy, dz;
  int duration;
} Heading;

typedef struct
{
  double x, y, z;
  double roll, pitch, yaw;
  int num_headings;
  Heading *headings;
} AiAircraft;

void ai_aircrafts_init(AiAircraft *aircrafts, int num_aircraft);
void ai_aircrafts_update(AiAircraft *aircrafts, int num_aircraft, int frame_counter);
void ai_aircrafts_create(AiAircraft *dest, const AiAircraft *src, int count);
void ai_aircraft_move(AiAircraft *aircraft, Heading heading);
void print_status(const AiAircraft *aircraft);
void normalize_vector(double *dx, double *dy, double *dz);

#endif // AI_AIRCRAFT_H
