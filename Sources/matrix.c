#include "../Headers/matrix.h"

matrix matrixCreate(int size){
    matrix m;
    m.size = size;
    m.cells = (int**)malloc(size * sizeof(int*));

    int i;
    for (i = 0; i < size; i++){
        m.cells[i] = (int*)calloc(size, sizeof(int));
    }

    return m;
}

void fill(int x, int y, pixel oldPixel, pixel newPixel, layer c){
    if (areEqualPixels(newPixel, oldPixel)){
        return;
    }

    int size = c.size;
    matrix tab_bool = matrixCreate(size);
    tab_bool.cells[y][x] = 1;
    points pile = newPoints();

    point* p = malloc(sizeof(point));
    p->x = x;
    p->y = y;
    int x0,y0;
    addPoint(&pile, *p);
    while(!(isEmptyPoints(pile))){
        *p = popPoints(&pile);
        x0 = p->x;
        y0 = p->y;

        if (areEqualPixels(c.cells[y0][x0], oldPixel)){
            c.cells[y0][x0] = newPixel;
            if (x0>0){
                p->x = x0-1;
                p->y = y0;
                if(!(tab_bool.cells[p->y][p->x])){
                    addPoint(&pile, *p);
                    tab_bool.cells[p->y][p->x] = 1;
                }
            }
            if (y0>0){
                p->y = y0-1;
                p->x = x0;
                if (!(tab_bool.cells[p->y][p->x])){
                    addPoint(&pile, *p);
                    tab_bool.cells[p->y][p->x] =1;
                }
            }
            if (x0<size-1){
                p->x = x0+1;
                p->y = y0;
                if (!(tab_bool.cells[p->y][p->x])){
                    addPoint(&pile, *p);
                    tab_bool.cells[p->y][p->x] = 1;
                }
            }
            if (y0<size-1){
                p->y = y0+1;
                p->x = x0;
                if (!(tab_bool.cells[p->y][p->x])){
                    addPoint(&pile, *p);
                    tab_bool.cells[p->y][p->x] = 1;
                }
            }
        }
    }

    free(pile);
    free(p);
}

void fusionLayers(layer c0, layer c1){
    int i, j;
    int size = c0.size;
    component alpha0;

    for (i = 0; i < size; i += 1){
        for (j = 0; j < size; j += 1){
            alpha0 = c0.cells[i][j].opacity;
            c1.cells[i][j].opacity = alpha0 + c1.cells[i][j].opacity * (255 - alpha0) / 255;
            c1.cells[i][j].color.red = c0.cells[i][j].color.red + c1.cells[i][j].color.red * (255 - alpha0) / 255;
            c1.cells[i][j].color.green = c0.cells[i][j].color.green + c1.cells[i][j].color.green * (255 - alpha0) / 255;
            c1.cells[i][j].color.blue = c0.cells[i][j].color.blue + c1.cells[i][j].color.blue * (255 - alpha0) / 255;
        }
    }
}

void cutLayer(layer c0, layer c1){
    int i,j;
    int size = c0.size;
    component alpha0;

    for (i = 0; i < size; i += 1){
        for (j = 0; j < size; j += 1){
            alpha0 = c0.cells[i][j].opacity;
            c1.cells[i][j].opacity = c1.cells[i][j].opacity * alpha0 / 255;
            c1.cells[i][j].color.red = c1.cells[i][j].color.red * alpha0 / 255;
            c1.cells[i][j].color.green = c1.cells[i][j].color.green * alpha0 / 255;
            c1.cells[i][j].color.blue = c1.cells[i][j].color.blue * alpha0 / 255;
        }
    }
}

int areEqualPixels(pixel p1, pixel p2){

    return (p1.color.red == p2.color.red && p1.color.green == p2.color.green && p1.color.blue == p2.color.blue && p1.opacity == p2.opacity);
}
