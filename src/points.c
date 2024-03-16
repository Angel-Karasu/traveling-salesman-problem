#include <stdio.h>

#include "globals.h"

/* Change values to those desired */
char const *points[] = {"A", "B", "C", "D", "E"}; 
int const distance_points[NB_POINTS][NB_POINTS] = {
    {0, 177, 652, 184, 303},
    {177, 0, 663, 230, 388},
    {652, 663, 0, 831, 953},
    {184, 230, 831, 0, 159},
    {303, 388, 953, 159, 0}
};
/* Don't forget to modify the number of cities in `src/globals.h`*/

int starting_point;
void choose_starting_point() {
    do {
        starting_point = 0;
        printf("Cities :\n");
        for (int i=0; i<NB_POINTS; i++) printf("  %d. %s\n", i, points[i]);
        printf("Choose the city to start with number: ");
        scanf("%d", &starting_point);
    } while (starting_point < 0 || starting_point >= NB_POINTS);
    printf("\nYou start in %s\n\n", points[starting_point]);
}
