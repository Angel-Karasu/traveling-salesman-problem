#include "utilities.h"

void greedy_proximity() {
    init_path();
    
    int actual_point = starting_point;
    for (int i=0; i<NB_POINTS-1; i++) {
        couple min = {i, __INT_MAX__};
        for (int j=i; j<NB_POINTS-1; j++) if (distance_points[actual_point][path[j]] < min.y) {
            min.x = j; min.y = distance_points[actual_point][path[j]];
        }
        swap_path(i, min.x);
        actual_point = path[i];
    }

    copy_path_to_min_path();
    show_min_path("Greedy proximity");
}