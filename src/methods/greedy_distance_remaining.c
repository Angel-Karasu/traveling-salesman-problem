#include "utilities.h"

void swap_couple(int i, int j, couple array[NB_CITIES-1]) {
    couple temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void greedy_distance_remaining() {
    init_path();
    
    couple array[NB_CITIES-1];
    for (int i=0; i<NB_CITIES-1; i++) {
        couple c = {path[i], distance_cities[path[i]][starting_city]};
        for (int j=0; j<NB_CITIES-1; j++) c.y += distance_cities[path[i]][path[j]];
        array[i] = c;
    }

    for (int i=0; i<NB_CITIES-1; i++) {
        couple min = {i, __INT_MAX__};
        for (int j=i; j<NB_CITIES-1; j++) if (array[j].y < min.y) {
            min.x = j; min.y = array[j].y;
        }
        swap_path(i, min.x); swap_couple(i, min.x, array);
        for (int j=i+1; j<NB_CITIES-1; j++) array[j].y -= distance_cities[path[i]][array[j].x];
    }
    copy_path_to_min_path();
    show_min_path("Greedy distance remaining");
}