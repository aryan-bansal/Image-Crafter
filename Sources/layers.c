#include "../Headers/layers.h"

layer newLayer(int size){
    layer *c = (layer*)malloc(sizeof(layer));

    if(NULL == c){
        fprintf(stderr, "Error during memory allocation of a newPixel layer.\n");
        exit(EXIT_FAILURE);
    }

    c->size = size;
    c->cells = (pixel**)malloc(size * sizeof(pixel*));

    if(NULL == c->cells){
        fprintf(stderr,"Error during memory allocation of the cells array of the layer.\n");
        exit(EXIT_FAILURE);
    }

    pixel pix = newPixel();

    int i, j;
    for(i = 0; i < size; i += 1){
        c->cells[i] = (pixel*)malloc(size * sizeof(pixel));

        if (NULL == c->cells[i]){
            fprintf(stderr, "Error during the allocation of one of the rows of the image.\n");
            exit(EXIT_FAILURE);
        }

        for(j = 0; j < size; j += 1){
            c->cells[i][j] = pix;
        }
    }
    return *c;
}

void freeLayer(layer* c){
    int i;
    int size = c->size;


    for(i = 0; i < size; i += 1){
        free(c->cells[i]);
    }

    free(c->cells);
}

void printLayer(layer c){
    int size = c.size;
    int i,j;

    for(i = 0; i < size; i += 1){
        for(j = 0; j < size; j += 1){
            printf("%d %d %d / ", c.cells[i][j].color.red, c.cells[i][j].color.green, c.cells[i][j].color.blue);
        }
        printf("\n-- -- --\n");
    }
}

pile_of_layers newPile(void){
    pile_of_layers *p_layers = (pile_of_layers*)malloc(sizeof(pile_of_layers));

    if (NULL == p_layers){
        fprintf(stderr, "Error during the allocation of memory for a new pile of layers.\n");
        exit(EXIT_FAILURE);
    }

    p_layers->top = -1;
    return *p_layers;
}

void pushPile(pile_of_layers *p_layers, layer c){

    if (SIZE_OF_STACK-1 == p_layers->top){
        fprintf(stderr, "Stack is full!\n");
        return;
    }

    p_layers->top += 1;
    p_layers->stack[p_layers->top] = c;
}

layer popPile(pile_of_layers *p_layers){
    if (p_layers->top < 0){
        printf("Pile is empty, cannot pop last element!\n");
        return newLayer(0);
    }

    layer* e = malloc(sizeof(layer));
    *e = p_layers->stack[p_layers->top];
    p_layers->top -= 1;
    return *e;
}

void popFreeLayer(pile_of_layers *p_layers){
    if (p_layers->top < 0){
        printf("Pile is empty, cannot pop last element!\n");
        return;
    }

    layer* e = malloc(sizeof(layer));
    *e = p_layers->stack[p_layers->top];
    p_layers->top -= 1;
    freeLayer(e);
}
