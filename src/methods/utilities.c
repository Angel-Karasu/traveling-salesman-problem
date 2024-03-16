#include <stdio.h>

#include "../globals.h"

int min_path[NB_POINTS];
int path[NB_POINTS-1];

void copy_path_to_min_path() {
    int dist = distance_points[starting_point][path[0]] + distance_points[path[NB_POINTS-2]][starting_point];
    int i = 0;
    while (dist<min_path[0] && i<NB_POINTS-2) {
        dist += distance_points[path[i]][path[i+1]];
        i++;
    }

    if (dist < min_path[0]) {
        min_path[0] = dist;
        for (int i=1; i<NB_POINTS; i++) min_path[i] = path[i-1];
    }
}

void init_path() {
    min_path[0] = __INT_MAX__;
    for (int i = 0; i < NB_POINTS-1; i++) path[i] = i + (i >= starting_point);
}

void show_min_path(char method[]) {
    printf("%s : %s -> ", method, points[starting_point]);
    for (int i=1; i<NB_POINTS; i++) printf("%s -> ", points[min_path[i]]);
    printf("%s : %d km\n", points[starting_point], min_path[0]);
}

void swap_path(int i, int j) {
    int temp = path[i];
    path[i] = path[j];
    path[j] = temp;
}