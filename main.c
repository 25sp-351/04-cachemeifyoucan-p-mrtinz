#include <stdio.h>
#include <stdlib.h>
#include "rod_cut.h"
#include "cache.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    RodCuttingData rod_data;
    if (!read_rod_data(argv[1], &rod_data)) {
        fprintf(stderr, "Error reading rod data from file.\n");
        return 1;
    }

    Cache cache;                // Fix: Declare a cache object
    initialize_cache(&cache);   // Fix: Initialize the cache

    int rod_length;
    while (printf("Enter rod length: "), scanf("%d", &rod_length) == 1) {
        int cut_counts[MAX_CUT_OPTIONS] = {0};
        int optimal_value = rod_cut_recursive(rod_length, &rod_data, cut_counts, &cache);  // Fix: Pass cache
        print_cut_results(rod_length, optimal_value, cut_counts, &rod_data);
    }

    return 0;
}
