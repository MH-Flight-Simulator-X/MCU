
#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "../include/cglm/cglm.h"
#include "aircraft.h"


void generate_mvp_matrix(Sprite *sprite, Aircraft *aircraft, mat4 result);

void print_matrix(mat4 matrix);

#endif // TRANSFORMATION_H
