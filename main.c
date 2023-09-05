#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    char Format[3];
    int Width;
    int Height;
    int MaxColorValue;
} PPMHeader;

int main() {
    char filename[100];
    printf("Enter PPM filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    
    if (!file) {
        printf("ERROR! can't open this file.\n");
        return 1;
    }

    char MagN[3];
    fread(MagN, sizeof(char), 2, file);

    if (MagN[0] == 'P' && MagN[1] == '6'){
        PPMHeader ppmHeader;
        fscanf(file, "%d %d\n%d\n", &ppmHeader.Width, &ppmHeader.Height, &ppmHeader.MaxColorValue);

        unsigned char** PixelData;
        PixelData = (unsigned char**)malloc(ppmHeader.Height * sizeof(unsigned char*));

        for(int i = 0; i < ppmHeader.Height; i++){
            PixelData[i] = (unsigned char*)malloc(3 * ppmHeader.Width * sizeof(unsigned char));
        }

        for (int row = 0; row < ppmHeader.Height; row++){
            fread(PixelData[row], 1, 3 * ppmHeader.Width, file);
        }

        int PrintPixels = 5;
        for (int i = 0; i < PrintPixels; i++){
            printf("Pixel %d: R=%d, G=%d, B=%d\n", i + 1,
            PixelData[i / ppmHeader.Width][3 * (i % ppmHeader.Width)],
            PixelData[i / ppmHeader.Width][3 * (i % ppmHeader.Width) + 1],
            PixelData[i / ppmHeader.Width][3 * (i % ppmHeader.Width) + 2]);
        }

        for (int i = 0; i < ppmHeader.Height; i++){
            free(PixelData[i]);
        }
        free(PixelData);
    }

    else{
        printf("OOPS! unsupported image type.\n");
    }
    fclose(file);

    return 0;
}
