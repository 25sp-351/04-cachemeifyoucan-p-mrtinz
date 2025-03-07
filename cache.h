#ifndef CACHE_H
#define CACHE_H

#include "rod_cut.h"

#define MAX_CACHE_SIZE 100

typedef struct {
    int rod_length;
    int best_value;
    int cut_counts[MAX_CUT_OPTIONS];
} CacheEntry;

typedef struct {
    CacheEntry entries[MAX_CACHE_SIZE];
    int size;
} Cache;

void initialize_cache(Cache *cache);
int check_cache(Cache *cache, int rod_length, int *best_value, int *cut_counts);
void update_cache(Cache *cache, int rod_length, int best_value, int *cut_counts);

#endif
