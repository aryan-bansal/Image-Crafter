#include "Headers/layers.h"
#include "Headers/machine.h"
#include "Headers/ppm.h"


int main(int argc, char* argv[]){

    if (argc == 1){
        int size;
        char buf[256];
        fgets(buf, 256, stdin);
        sscanf(buf, "%d", &size);

        machine mach = createMachine(size);

        char c = '\0';
        while (c != EOF){
            c = fgetc(stdin);
            readData(c, &mach);
        }

        layer lay = popPile(&(mach.layers));
        creationPPM(lay, size, stdout);

        return 0;
    }


    if (argc == 2){
        FILE* fd = fopen(argv[1], "r");
        if (fd == NULL){
            fprintf(stderr, "Error while opening file.\n");
            exit(2);
        }

        char buf[256];
        int size;
        fgets(buf, 256, fd);
        sscanf(buf, "%d", &size);

        machine mach = createMachine(size);

        char c = '\0';
        while (c != EOF) {
            c = fgetc(fd);
            readData(c, &mach);
        }

        layer lay = popPile(&(mach.layers));
        creationPPM(lay, size, stdout);

        return 0;
    }


    if (argc == 3){
        FILE* fd = fopen(argv[1], "r");
        if (fd == NULL){
            fprintf(stderr, "Error while opening file.\n");
            exit(2);
        }

        char buf[256];
        int size;
        fgets(buf, 256, fd);
        sscanf(buf, "%d", &size);

        machine mach = createMachine(size);

        char c = '\0';
        while (c != EOF){
            c = fgetc(fd);
            readData(c, &mach);
        }

        fclose(fd);

        layer lay = popPile(&(mach.layers));
        FILE* fdout = fopen(argv[2], "wb");
        creationPPM(lay, size, fdout);

        return 0;
    }

    if (argc > 3){
        fprintf(stderr, "Oops, Only 2 arguments allowed.\n");

        FILE* fd = fopen(argv[1], "r");
        if (fd == NULL){
            fprintf(stderr, "Error while opening file.\n");
            exit(2);
        }

        char buf[256];
        int size;
        fgets(buf, 256, fd);
        sscanf(buf, "%d", &size);

        machine mach = createMachine(size);

        char c = '\0';
        while (c != EOF) {
            c = fgetc(fd);
            readData(c, &mach);
        }

        fclose(fd);

        layer lay = popPile(&(mach.layers));

        FILE* fdout = fopen(argv[2], "wb");
        creationPPM(lay, size, fdout);

        return 0;
    }
}
