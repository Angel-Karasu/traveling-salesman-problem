#include <stdio.h>

#include "globals.h"

/* Change values to those desired */
int starting_city = 0;
char const *city_names[] = {"Nancy", "Metz", "Paris", "Reims", "Troyes"};
int distance_cities[NB_CITIES][NB_CITIES] = {
    {0, 55, 303, 188, 183},
    {55, 0, 306, 176, 203},
    {303, 306, 0, 142, 153},
    {188, 176, 142, 0, 123},
    {183, 203, 153, 123, 0}
};
/* Don't forget to modify the number of cities in `globals.h` */

int min_path[NB_CITIES];
int path[NB_CITIES-1];

int calculate_distance() {
    int distance = distance_cities[starting_city][path[0]];

    for (int i=0; i<NB_CITIES-2; i++) distance += distance_cities[path[i]][path[i+1]];

    distance += distance_cities[path[NB_CITIES-2]][starting_city];

    return distance;
}

void copy_path() {
    for (int i=1; i<NB_CITIES; i++) min_path[i] = path[i-1];
}

void show_min_path(char method[], int *path) {
    printf("%s : %s -> ", method, city_names[starting_city]);
    for (int i=1; i<NB_CITIES; i++) printf("%s -> ", city_names[path[i]]);
    printf("%s : %dkm\n", city_names[starting_city], path[0]);
}

void init_path() {
    min_path[0] = __INT_MAX__;
    for (int i = 0; i < NB_CITIES-1; i++) path[i] = i + (i >= starting_city);
}

int main() {
    init_path();

    brute_force(0);
    show_min_path("Brute force", min_path);

    shuffle();
    show_min_path("Random", min_path);

    return 0;
}
