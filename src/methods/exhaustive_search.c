#include "utilities.h"

void permute(int start) {
    if (start > NB_POINTS-2) copy_path_to_min_path();

    for (int i = start; i < NB_POINTS-1 - (start < (NB_POINTS-1)/2); i++) {
        swap_path(start, i);
        permute(start+1);
        swap_path(start, i);
    }
}

void exhaustive_search() {
    init_path();

    permute(0);

    show_min_path("Exhaustive search");
}