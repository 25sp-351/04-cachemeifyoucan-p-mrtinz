#include <stdio.h>
#include <stdlib.h>
#include "rod_cut.h"

int read_rod_data(const char *filename, RodCuttingData *rod_data) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 0;
    }

    rod_data->num_options = 0;

    while (fscanf(file, "%d,%d", &rod_data->options[rod_data->num_options].length,
                  &rod_data->options[rod_data->num_options].value) == 2) {
        if (rod_data->options[rod_data->num_options].length <= 0 || 
            rod_data->options[rod_data->num_options].value < 0) {
            fprintf(stderr, "Error: Invalid data in file.\n");
            fclose(file);
            return 0;
        }

        rod_data->num_options++;
        if (rod_data->num_options >= MAX_CUT_OPTIONS) {
            fprintf(stderr, "Warning: Maximum number of cutting options reached.\n");
            break;
        }
    }

    fclose(file);
    return 1;
}
