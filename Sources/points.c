#include "../Headers/points.h"

points newPoints(void){
    return NULL;
}

points addEffectPoint(points l, point p){
    points res = (points)malloc(sizeof(struct Node__));
    if (NULL == res){
        fprintf(stderr, "Error during the allocation of memory for a newPixel opacity bucket.\n");
        exit(EXIT_FAILURE);
    }

    res->p = p;
    res->next = l;
    return res;
}

void addPoint(points *l, point p){
    *l = addEffectPoint(*l, p);
}

int isEmptyPoints(points p){
    return p == NULL;
}

point popPoints(points *l){
    point* p = malloc(sizeof(point));
    *p = (*l)->p;
    *l = (*l)->next;
    return *p;
}
