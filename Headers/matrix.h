#ifndef MATRIX_H
#define MATRIX_H

#include "pixels.h"
#include "layers.h"

typedef struct {
    int size;
    int** cells;
} matrix;

matrix matrixCreate(int size);

void fill(int x, int y, pixel oldPixel, pixel newPixel, layer c);

void fusionLayers(layer c0, layer c1);

void cutLayer(layer c0, layer c1);

int areEqualPixels(pixel p1, pixel p2);

#endif
