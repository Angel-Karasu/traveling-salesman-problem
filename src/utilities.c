#include <stdio.h>

#include "../globals.h"

int min_path[NB_CITIES];
int path[NB_CITIES-1];

int calculate_distance() {
    int distance = distance_cities[starting_city][path[0]];
    for (int i=0; i<NB_CITIES-2; i++) distance += distance_cities[path[i]][path[i+1]];

    return distance + distance_cities[path[NB_CITIES-2]][starting_city];
}

void copy_path_to_min_path() {
    int d = calculate_distance();
    if (d < min_path[0]) {
        min_path[0] = d;
        for (int i=1; i<NB_CITIES; i++) min_path[i] = path[i-1];
    }
}

void init_path() {
    min_path[0] = __INT_MAX__;
    for (int i = 0; i < NB_CITIES-1; i++) path[i] = i + (i >= starting_city);
}

void show_min_path(char method[]) {
    printf("%s : %s -> ", method, city_names[starting_city]);
    for (int i=1; i<NB_CITIES; i++) printf("%s -> ", city_names[min_path[i]]);
    printf("%s : %dkm\n", city_names[starting_city], min_path[0]);
}

void swap_path(int i, int j) {
    int temp = path[i];
    path[i] = path[j];
    path[j] = temp;
}