#include "../Headers/ppm.h"

color* createBtm(layer c, int size){
    color* btm = (color*)malloc(sizeof(color) * size*size);

    int i,j;
    for (i = 0; i < size; i += 1){
        for (j = 0; j < size; j += 1){
            btm[i*size+j] = c.cells[i][j].color;
        }
    }

    return btm;
}

void creationPPM(layer c, int size, FILE* fd){
    color* btm = createBtm(c,size);
    fprintf(fd, "P6\n%d %d\n255\n", size, size);
    fwrite(btm, sizeof(color), size*size, fd);
}
