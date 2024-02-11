#include "methods.h"
#include "globals.h"

/* Change values to those desired */
int const starting_city = 1;
char const *city_names[] = {"Nancy", "Metz", "Paris", "Reims", "Troyes"};
int const distance_cities[NB_CITIES][NB_CITIES] = {
    {0, 55, 303, 188, 183},
    {55, 0, 306, 176, 203},
    {303, 306, 0, 142, 153},
    {188, 176, 142, 0, 123},
    {183, 203, 153, 123, 0}
};
/* Don't forget to modify the number of cities in `globals.h`*/

int main() {
    brute_force();
    greedy_distance_remaining();
    shuffle();
    static_sort();

    return 0;
}