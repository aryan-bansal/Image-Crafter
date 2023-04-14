#include "../Headers/pixels.h"

pixel newPixel(void){
    pixel *pix = (pixel*)malloc(sizeof(pixel));

    if (NULL == pix){
        fprintf(stderr, "Error during the allocation of memory for a newPixel pixel.\n");
        exit(EXIT_FAILURE);
    }

    pix->color = newColor(0,0,0);
    pix->opacity = 0;
    return *pix;
}
