#ifndef LAYERS_H
#define LAYERS_H

#include "colors.h"
#include "pixels.h"
#include "points.h"

#define SIZE_OF_STACK 10

typedef struct {
    int size;
    pixel** cells;
} layer;

layer newLayer(int size);

void freeLayer(layer* c);

void printLayer(layer c);

typedef struct {
    layer stack[SIZE_OF_STACK];
    int top;
} pile_of_layers;

pile_of_layers newPile(void);

void pushPile(pile_of_layers* p_layers, layer c);

layer popPile(pile_of_layers* p_layers);

void popFreeLayer(pile_of_layers *p_layers);

#endif
