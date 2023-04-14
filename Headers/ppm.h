#ifndef PPM_H
#define PPM_H

#include "layers.h"

color* createBtm(layer c, int size);

void creationPPM(layer c, int size, FILE* fd);

#endif
