#include <stdio.h>
#include "rod_cut.h"
#include "cache.h"

int rod_cut_recursive(int remaining_length, RodCuttingData *rod_data, int *cut_counts, Cache *cache) {
    if (remaining_length == 0) return 0;

    int cached_value;
    if (check_cache(cache, remaining_length, &cached_value, cut_counts)) {
        return cached_value;
    }

    int max_value = 0;
    int best_cut_counts[MAX_CUT_OPTIONS] = {0};

    for (int i = 0; i < rod_data->num_options; i++) {
        if (rod_data->options[i].length <= remaining_length) {
            int temp_cut_counts[MAX_CUT_OPTIONS] = {0};
            int current_value = rod_data->options[i].value +
                rod_cut_recursive(remaining_length - rod_data->options[i].length, rod_data, temp_cut_counts, cache);

            if (current_value > max_value) {
                max_value = current_value;
                for (int j = 0; j < MAX_CUT_OPTIONS; j++) {
                    best_cut_counts[j] = temp_cut_counts[j];
                }
                best_cut_counts[i]++;
            }
        }
    }

    for (int j = 0; j < MAX_CUT_OPTIONS; j++) {
        cut_counts[j] = best_cut_counts[j];
    }

    update_cache(cache, remaining_length, max_value, cut_counts);
    return max_value;
}
