#include <stdio.h>
#include "rod_cut.h"

void print_cut_results(int rod_length, int optimal_value, int *cut_counts, RodCuttingData *rod_data) {
    int total_cuts = 0;
    int used_length = 0;

    for (int i = 0; i < rod_data->num_options; i++) {
        if (cut_counts[i] > 0) {
            printf("%d @ %d = %d\n", cut_counts[i], rod_data->options[i].length, 
                   cut_counts[i] * rod_data->options[i].value);
            total_cuts += cut_counts[i];
            used_length += cut_counts[i] * rod_data->options[i].length;
        }
    }

    int remainder = rod_length - used_length;
    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", optimal_value);
}
