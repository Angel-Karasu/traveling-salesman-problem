#define NB_CITIES 5

extern char const *city_names[];
extern int const distance_cities[NB_CITIES][NB_CITIES];
extern int const starting_city;

extern int min_path[NB_CITIES];
extern int path[NB_CITIES-1];