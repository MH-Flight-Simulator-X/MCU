#ifndef HEADING_H
#define HEADING_H

#include "ai_aircraft.h"
#include <math.h>
#include <string.h>

// Macro to get the length of an array
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

// Define heading lists
static Heading heading_list1[] = {
    {1.0, 0.0, 0.0, 120},
    {0.0, 1.0, 0.0, 180},
    {0.0, 0.0, 1.0, 60},
    {-1.0, 1.0, 0.0, 240},
    {0.0, -1.0, -1.0, 120}};
static const int heading_list1_size = ARRAY_LENGTH(heading_list1);

static Heading heading_list2[] = {
    {-1.0, 0.0, 0.0, 100},
    {0.0, -1.0, 0.0, 150},
    {1.0, 1.0, 0.0, 200},
    {-0.5, 0.5, 0.0, 80},
    {0.0, 0.0, -1.0, 130}};
static const int heading_list2_size = ARRAY_LENGTH(heading_list2);

static Heading heading_list3[] = {
    {0.5, 0.5, 0.5, 90},
    {-0.5, 0.5, -0.5, 160},
    {1.0, 0.0, -1.0, 110},
    {-1.0, 1.0, 0.0, 70},
    {0.0, 1.0, -1.0, 140}};
static const int heading_list3_size = ARRAY_LENGTH(heading_list3);

static AiAircraft original_aircrafts[] = {
    // Aircraft 1
    {.x = 0.0, .y = 0.0, .z = 0.0, .roll = 0.0, .pitch = 0.0, .yaw = 0.0, .headings = heading_list1, .num_headings = heading_list1_size},
    // Aircraft 2
    {.x = 50.0, .y = -20.0, .z = 10.0, .roll = 0.0, .pitch = 0.0, .yaw = 0.0, .headings = heading_list2, .num_headings = heading_list2_size},
    // Aircraft 3
    {.x = -30.0, .y = 40.0, .z = -15.0, .roll = 0.0, .pitch = 0.0, .yaw = 0.0, .headings = heading_list3, .num_headings = heading_list3_size}};

static const int num_aircrafts = ARRAY_LENGTH(original_aircrafts);

#endif // HEADING_H
