#include "../Headers/colors.h"

color newColor(component red, component green, component blue){
    color *col = (color*)malloc(sizeof(color));

    if (NULL == col){
        fprintf(stderr, "Error during memory allocation of the color.\n");
        exit(EXIT_FAILURE);
    }

    col->red = red;
    col->green = green;
    col->blue = blue;
    return *col;
}
