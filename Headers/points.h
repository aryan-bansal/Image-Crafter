#ifndef POINTS_H
#define POINTS_H

#include "colors.h"

typedef struct point {
    int x;
    int y;
} point;

typedef struct Node__ *points;
struct Node__ {
    point p;
    points next;
};

points newPoints(void);

points addEffectPoint(points l, point p);

void addPoint(points *l, point p);

int isEmptyPoints(points p);

point popPoints(points *l);

#endif
