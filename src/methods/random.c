#include <stdlib.h>
#include <time.h>

#include "utilities.h"

void shuffle() {
    init_path();
    srand(time(NULL));

    for (int i=0; i<NB_POINTS-1; i++) swap_path(rand() % (NB_POINTS-1), i);
    
    copy_path_to_min_path();

    show_min_path("Random");
}