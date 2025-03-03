#include "rod_cut.h"  // Ensure MAX_CUT_OPTIONS is defined
#include "cache.h"
#include <string.h>

void initialize_cache(Cache *cache) {
    cache->size = 0;
}

int check_cache(Cache *cache, int rod_length, int *best_value, int *cut_counts) {
    for (int i = 0; i < cache->size; i++) {
        if (cache->entries[i].rod_length == rod_length) {
            *best_value = cache->entries[i].best_value;
            memcpy(cut_counts, cache->entries[i].cut_counts, sizeof(int) * MAX_CUT_OPTIONS);
            return 1;
        }
    }
    return 0;
}

void update_cache(Cache *cache, int rod_length, int best_value, int *cut_counts) {
    if (cache->size < MAX_CACHE_SIZE) {
        cache->entries[cache->size].rod_length = rod_length;
        cache->entries[cache->size].best_value = best_value;
        memcpy(cache->entries[cache->size].cut_counts, cut_counts, sizeof(int) * MAX_CUT_OPTIONS);
        cache->size++;
    } else {
        for (int i = 1; i < MAX_CACHE_SIZE; i++) {
            cache->entries[i - 1] = cache->entries[i];
        }
        cache->entries[MAX_CACHE_SIZE - 1].rod_length = rod_length;
        cache->entries[MAX_CACHE_SIZE - 1].best_value = best_value;
        memcpy(cache->entries[MAX_CACHE_SIZE - 1].cut_counts, cut_counts, sizeof(int) * MAX_CUT_OPTIONS);
    }
}
