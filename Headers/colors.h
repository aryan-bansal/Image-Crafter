#ifndef COLORS_H
#define COLORS_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char component;

typedef struct {
    component red;
    component green;
    component blue;
} color;

color newColor(component red, component green, component blue);

#endif
