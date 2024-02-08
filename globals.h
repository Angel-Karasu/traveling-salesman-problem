#include <stdlib.h>

#define NB_CITIES 5

extern int distance_cities[NB_CITIES][NB_CITIES];
extern int min_path[NB_CITIES];
extern int path[NB_CITIES-1];
extern int starting_city;

int calculate_distance();
void copy_path();

void brute_force(int start);

void shuffle();