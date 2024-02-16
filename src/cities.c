#include <stdio.h>

#include "globals.h"

/* Change values to those desired */
char const *city_names[] = {"Armenia", "Bogota", "Cartagena", "Neiva", "San Agustin"}; 
int const distance_cities[NB_CITIES][NB_CITIES] = {
    {0, 177, 652, 184, 303},
    {177, 0, 663, 230, 388},
    {652, 663, 0, 831, 953},
    {184, 230, 831, 0, 159},
    {303, 388, 953, 159, 0}
};
/* Don't forget to modify the number of cities in `src/globals.h`*/

int starting_city;
void choose_city() {
    do {
        starting_city = 0;
        printf("Cities :\n");
        for (int i=0; i<NB_CITIES; i++) printf("  %d. %s\n", i, city_names[i]);
        printf("Choose the city to start with number: ");
        scanf("%d", &starting_city);
    } while (starting_city < 0 || starting_city >= NB_CITIES);
    printf("\nYou start in %s\n\n", city_names[starting_city]);
}
