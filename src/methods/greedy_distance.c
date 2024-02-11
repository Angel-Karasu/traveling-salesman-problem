#include "../utilities.h"

#include <stdio.h>

int calculate_distance(int actual_cities, int visited_cities) {
    int d = 0;
    for (int i=visited_cities; i<NB_CITIES-1; i++) d += distance_cities[actual_cities][path[i]];
    return d;
}

void greedy_distance() {
    init_path();
    
    couple array[NB_CITIES-1];
    for (int i=0; i<NB_CITIES-1; i++) {
        couple c = {i, calculate_distance(i, 0)};
        array[i] = c;
        printf("%d-%d\n", c.x, c.y);
    }

    show_min_path("Greedy distance");
}