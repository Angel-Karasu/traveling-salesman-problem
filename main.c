#include "methods.h"
#include "globals.h"

/* Change values to those desired */
int const starting_city = 1;
char const *city_names[] = {"Armenia", "Bogota", "Cartagena", "Neiva", "San Agustin"}; 
int const distance_cities[NB_CITIES][NB_CITIES] = {
    {0, 177, 652, 184, 303},
    {177, 0, 663, 230, 388},
    {652, 663, 0, 831, 953},
    {184, 230, 831, 0, 159},
    {303, 388, 953, 159, 0}
};
/* Don't forget to modify the number of cities in `globals.h`*/

int main() {
    brute_force();
    greedy_distance_remaining();
    greedy_proximity();
    shuffle();
    static_sort();

    return 0;
}