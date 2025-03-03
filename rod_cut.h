#ifndef ROD_CUT_H
#define ROD_CUT_H

#define MAX_CUT_OPTIONS 100

typedef struct {
    int length;
    int value;
} CutOption;

typedef struct {
    CutOption options[MAX_CUT_OPTIONS];
    int num_options;
} RodCuttingData;

#include "cache.h"
int read_rod_data(const char *filename, RodCuttingData *rod_data);
int rod_cut_recursive(int remaining_length, RodCuttingData *rod_data, int *cut_counts, Cache *cache);
void print_cut_results(int rod_length, int optimal_value, int *cut_counts, RodCuttingData *rod_data);

#endif
