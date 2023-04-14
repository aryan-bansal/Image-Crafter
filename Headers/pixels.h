#ifndef PIXELS_H
#define PIXELS_H

#include "colors.h"

typedef struct {
    color color;
    component opacity;
} pixel;

pixel newPixel(void);

#endif
