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
  int counter;
  int status;
  int id;
} AiAircraft;

void ai_aircraft_init(AiAircraft *aircraft, int num_aircraft);
void ai_aircraft_update_pose(AiAircraft *aircraft, int num_aircraft, int frame_counter);
void ai_aircraft_create(AiAircraft *dest, const AiAircraft *src, int count);
void ai_aircraft_move(AiAircraft *aircraft, Heading heading);
void ai_aircraft_update_status(AiAircraft * crafts, int num_aircraft);
void normalize_vector(double *dx, double *dy, double *dz);

#endif // AI_AIRCRAFT_H
