#include "globals.h"

void brute_force(int start) {
    if (start > NB_CITIES-2) {
        int d = calculate_distance();
        if (d < min_path[0]) {
            min_path[0] = d;
            copy_path();
        }
    }

    for (int i = start; i < NB_CITIES-1; i++) {
        int temp = path[start];
        path[start] = path[i];
        path[i] = temp;

        brute_force(start+1);
        
        temp = path[start];
        path[start] = path[i];
        path[i] = temp;
    }
}