#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t IDLength;
    uint8_t ColorMapType;
    uint8_t ImageType;
    uint16_t ColorMapStart;
    uint16_t ColorMapLength;
    uint8_t colorMapDepth;
    uint16_t XOrigin;
    uint16_t YOrigin;
    uint16_t Width;
    uint16_t Height;
    uint8_t BitsPerPixel;
    uint8_t ImageDescriptor;
} TGAHeader;

typedef struct {
    char Format[3];
    int Width;
    int Height;
    int MaxColorValue;
} PPMHeader;

int main(){
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("ERROR opening the file.\n");
        return 1;
    }

    uint8_t ImageType;
    fread(&ImageType, sizeof(uint8_t), 1, file);

    if (ImageType == 1 || ImageType == 2 || ImageType == 3 || ImageType == 9 || ImageType == 10 || ImageType == 11){
        TGAHeader tgaHeader;
        fread(&tgaHeader, sizeof(TGAHeader), 1, file);

        printf("Image Width: %d\n", tgaHeader.Width);
        printf("Image Height: %d\n", tgaHeader.Height);
        printf("Image Size: %d bytes\n", tgaHeader.Width * tgaHeader.Height * tgaHeader.BitsPerPixel / 8);
    }
    else if (ImageType == 'P' && fgetc(file) == '6'){
        PPMHeader ppmHeader;
        fscanf(file, "%d %d\n%d\n", &ppmHeader.Width, &ppmHeader.Height, &ppmHeader.MaxColorValue);

        printf("Image Width: %d\n", ppmHeader.Width);
        printf("Image Height: %d\n", ppmHeader.Height);
        printf("Image Size: %d bytes\n", ppmHeader.Width * ppmHeader.Height * 3);
    }
    else {
        printf("unsupported image type.\n");
    }

    fclose(file);
    return 0;
}
