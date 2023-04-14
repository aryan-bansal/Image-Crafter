#ifndef BUCKETS_H
#define BUCKETS_H

#include "colors.h"

typedef struct Node *bucket_color;
struct Node {
    color color;
    bucket_color next;
};

bucket_color newBucketColor(void);

int isEmptyBucketColor(bucket_color bucket);

bucket_color addEffectColor(bucket_color bucket, color c);

void addColor(bucket_color *bucket, color c);

void videoBucketColor(bucket_color *bucket);

typedef struct Node_ *bucket_opacity;
struct Node_ {
    component opacity;
    bucket_opacity next;
};

bucket_opacity newBucketOpacity(void);

int isEmptyBucketOpacity(bucket_opacity bucket);

bucket_opacity addEffectOpacity(bucket_opacity bucket, component opacity);

void addOpacity(bucket_opacity *bucket, component opacity);

void videoBucketOpacity(bucket_opacity *bucket);

#endif
