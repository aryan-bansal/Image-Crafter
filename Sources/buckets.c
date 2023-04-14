#include "../Headers/buckets.h"

bucket_color newBucketColor(void){
    return NULL;
}

int isEmptyBucketColor(bucket_color bucket){
    return NULL == bucket;
}

bucket_color addEffectColor(bucket_color bucket, color c){
    bucket_color res = (bucket_color)malloc(sizeof(struct Node));

    if(NULL == res){
        fprintf(stderr, "Error during memory allocation of a newPixel bucket of colors.\n");
        exit(EXIT_FAILURE);
    }

    res->color = c;
    res->next = bucket;
    return res;
}

void addColor(bucket_color *bucket, color c){
    *bucket = addEffectColor(*bucket, c);
}

void videoBucketColor(bucket_color *bucket){
    bucket_color to_delete = newBucketColor();

    while(!isEmptyBucketColor(*bucket)){
        to_delete = *bucket;
        *bucket = (*bucket)->next;
        free(to_delete);
    }
}

bucket_opacity newBucketOpacity(void){
    return NULL;
}

int isEmptyBucketOpacity(bucket_opacity bucket){
    return bucket == NULL;
}

bucket_opacity addEffectOpacity(bucket_opacity bucket, component opacity){
    bucket_opacity res = (bucket_opacity)malloc(sizeof(struct Node_));

    if(NULL == res){
        fprintf(stderr, "Error during memory allocation of a newPixel bucket of opacity.\n");
        exit(EXIT_FAILURE);
    }

    res->opacity = opacity;
    res->next = bucket;
    return res; }

void addOpacity(bucket_opacity *bucket, component opacity){
    *bucket = addEffectOpacity(*bucket, opacity);
}

void videoBucketOpacity(bucket_opacity *bucket){
    bucket_opacity to_delete = newBucketOpacity();

    while(!isEmptyBucketOpacity(*bucket)){
        to_delete = *bucket;
        *bucket = (*bucket)->next;
        free(to_delete);
    }
}
