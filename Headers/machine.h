#ifndef MACHINE_H
#define MACHINE_H

#include "layers.h"
#include "buckets.h"
#include "matrix.h"

typedef enum{
    north,
    east,
    south,
    west
} direction;

typedef struct {
    int pos[2];
    int markedPos[2];
    direction direction;
    bucket_color bucket_color;
    bucket_opacity bucket_opacity;
    pile_of_layers layers;
} machine;

machine createMachine(int size);

void readData(char character, machine *machine);

component avgOpacity(bucket_opacity bucket);

color avgColor(bucket_color bucket);

pixel currentLayerPixel(machine machine);

void forwardDirection(machine* machine);

void rotationClockwise(machine* machine);

void rotationAntiClockwise(machine* machine);

void traceLine(int init[2], int final[2], machine* machine);

int max(int a, int b);

int sameNonNullSign(int a, int b);

#endif
