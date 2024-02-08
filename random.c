#include <time.h>

#include "globals.h"

void shuffle() {
    srand(time(NULL));

    for (int i=0; i<NB_CITIES-1; i++) {
        int r = rand() % (NB_CITIES-1);
        int temp = path[r];
        path[r] = path[i];
        path[i] = temp;
    }
    min_path[0] = calculate_distance();
    copy_path();
}