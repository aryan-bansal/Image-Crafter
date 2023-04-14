#include "../Headers/machine.h"

machine createMachine(int size){
    machine *mach = (machine*)malloc(sizeof(machine));

    if(NULL == mach){
        fprintf(stderr, "Error during the allocation of memory for the new machine\n");
        exit(EXIT_FAILURE);
    }

    mach->pos[0] = 0;
    mach->pos[1] = 0;
    mach->markedPos[0] = 0;
    mach->markedPos[1] = 0;
    mach->direction = east;
    mach->bucket_color = newBucketColor();
    mach->bucket_opacity = newBucketOpacity();
    mach->layers = newPile();
    pushPile(&(mach->layers), newLayer(size));
    return *mach;
}

component avgOpacity(bucket_opacity bucket){
    int sum = 0;
    int cpt = 0;
    bucket_opacity tmp = bucket;

    if(isEmptyBucketOpacity(tmp)){
        component res = 255;
        return res;
    }

    else{
        while(!isEmptyBucketOpacity(tmp)){
            sum += tmp->opacity;
            tmp = tmp->next;
            cpt +=1;
        }
    free(tmp);

    component res = sum/cpt;
    return res;
    }
}

color avgColor(bucket_color bucket){
    int sum_red = 0;
    int sum_green = 0;
    int sum_blue = 0;
    int cpt = 0;
    bucket_color tmp = bucket;

    if(isEmptyBucketColor(tmp)){
        color res = newColor(0,0,0);
        return res;
    }

    else{
        while(!isEmptyBucketColor(tmp)){
            sum_red += tmp->color.red;
            sum_green += tmp->color.green;
            sum_blue += tmp->color.blue;

            tmp = tmp->next;
            cpt += 1;         }
        free(tmp);

        component red = sum_red/cpt;
        component green = sum_green/cpt;
        component blue = sum_blue/cpt;
        color res = newColor(red, green, blue);
        return res;
    }
}

pixel currentLayerPixel(machine machine){
    pixel pix = newPixel();
    component op = avgOpacity(machine.bucket_opacity);
    color avg = avgColor(machine.bucket_color);
    color col = newColor(avg.red*op/255,avg.green*op/255, avg.blue*op/255);
    pix.color = col;
    pix.opacity = op;
    return pix;
}

int max(int a, int b){
    if (a <= b){
        return b;
    }
    return a;
}

int sameNonNullSign(int a, int b){
    if (a*b > 0){
        return 1;
    }
    return 0;
}

void traceLine(int init[2], int final[2], machine* machine){
    int x0 = init[1];
    int y0 = init[0];
    int x1 = final[1];
    int y1 = final[0];

    int delta_x = x1 - x0;
    int delta_y = y1 - y0;
    int d = max(abs(delta_x), abs(delta_y));

    int s;
    if(sameNonNullSign(delta_x, delta_y)){
        s = 0;
    }
    else{
        s=1;
    }

    int x = x0*d + (d-s)/2;
    int y = y0*d + (d-s)/2;

    int i;
    pixel pixel_courant = currentLayerPixel(*machine);

    for (i = 0; i < d; i += 1){
        (machine->layers.stack[machine->layers.top].cells[y/d][x/d]).color = pixel_courant.color;
        (machine->layers.stack[machine->layers.top].cells[y/d][x/d]).opacity = pixel_courant.opacity;
        x += delta_x;
        y += delta_y;
    }

    (machine->layers.stack[machine->layers.top].cells[y1][x1]).color = pixel_courant.color;
    (machine->layers.stack[machine->layers.top].cells[y1][x1]).opacity = pixel_courant.opacity;
}

void forwardDirection(machine* machine){
    int y = machine->pos[0];
    int x = machine->pos[1];
    int size = machine->layers.stack[machine->layers.top].size;

    if(machine->direction == north){
        if((y-1) == -1){
            machine->pos[0] = size-1;
        }
        else machine->pos[0] = y-1;
    }

    else if(machine->direction == east){
        if((x+1) == size){
            machine->pos[1] = 0;
        }
        else machine->pos[1] = x+1;
    }

    else if(machine->direction == south){
        if((y+1) == size){
            machine->pos[0] = 0;
        }
        else machine->pos[0] = y+1;
    }

    else{
        if((x-1) == -1){
            machine->pos[1] = size-1;
        }
        else machine->pos[1] = x-1;
    }
}

void rotationClockwise(machine* machine){
    if(machine->direction == north){
        machine->direction = east;
    }
    else if(machine->direction == east){
        machine->direction = south;
    }
    else if(machine->direction == south){
        machine->direction = west;
    }
    else{
        machine->direction = north;
    }
}

void rotationAntiClockwise(machine* machine){
    if(machine->direction == north){
        machine->direction = west;
    }
    else if(machine->direction == east){
        machine->direction = north;
    }
    else if(machine->direction == south){
        machine->direction = east;
    }
    else{
        machine->direction = south;
    }
}

void readData(char character, machine *machine){
    int x,y;
    pixel pix = newPixel();

    switch(character)
    {
    case 'n':
        addColor(&(machine->bucket_color), newColor(0,0,0));
        break;
    case 'r':
        addColor(&(machine->bucket_color), newColor(255,0,0));
        break;
    case 'g':
        addColor(&(machine->bucket_color), newColor(0,255,0));
        break;
    case 'b':
        addColor(&(machine->bucket_color), newColor(0,0,255));
        break;
    case 'y':
        addColor(&(machine->bucket_color), newColor(255,255,0));
        break;
    case 'm':
        addColor(&(machine->bucket_color), newColor(255,0,255));
        break;
    case 'c':
        addColor(&(machine->bucket_color), newColor(0,255,255));
        break;
    case 'w':
        addColor(&(machine->bucket_color), newColor(255,255,255));
        break;
    case 't':
        addOpacity(&(machine->bucket_opacity), 0);
        break;
    case 'o':
        addOpacity(&(machine->bucket_opacity), 255);
        break;
    case 'i':
        videoBucketColor(&(machine->bucket_color));
        videoBucketOpacity(&(machine->bucket_opacity));
        break;
    case 'v':
        forwardDirection(machine);
        break;
    case 'h':
        rotationClockwise(machine);
        break;
    case 'a':
        rotationAntiClockwise(machine);
        break;
    case 'p':
        machine->markedPos[0] = machine->pos[0];
        machine->markedPos[1] = machine->pos[1];
        break;
    case 'l':
        traceLine(machine->pos, machine->markedPos, machine);
        break;
    case 'f':
        x = machine->pos[1];
        y = machine->pos[0];
        pix = currentLayerPixel(*machine);
        fill(x, y, machine->layers.stack[machine->layers.top].cells[y][x], pix, machine->layers.stack[machine->layers.top]);
        break;
    case 's':
        pushPile(&(machine->layers), newLayer(machine->layers.stack[machine->layers.top].size));
        break;
    case 'e':
        if (machine->layers.top<=0){
            return;
        }
        else {
            fusionLayers(machine->layers.stack[machine->layers.top],machine->layers.stack[machine->layers.top-1]);
            popFreeLayer(&(machine->layers));
            break;
        }
    case 'j':
        if (machine->layers.top<=0){
            return;
        }
        else {
            cutLayer(machine->layers.stack[machine->layers.top],machine->layers.stack[machine->layers.top-1]);
            popFreeLayer((&machine->layers));
        }
        break;

    default:
        break;
    }
}
