#include "utilities.h"

void greedy_proximity() {
    init_path();
    
    int actual_city = starting_city;
    for (int i=0; i<NB_CITIES-1; i++) {
        couple min = {i, __INT_MAX__};
        for (int j=i; j<NB_CITIES-1; j++) if (distance_cities[actual_city][path[j]] < min.y) {
            min.x = j; min.y = distance_cities[actual_city][path[j]];
        }
        swap_path(i, min.x);
        actual_city = path[i];
    }

    copy_path_to_min_path();
    show_min_path("Greedy proximity");
}