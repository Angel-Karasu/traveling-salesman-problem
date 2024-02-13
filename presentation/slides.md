---
marp: true
paginate: true
theme: default
class: lead
backgroundImage: url('https://marp.app/assets/hero-background.svg')
math: mathjax
---

# **Traveling Salesman Problem**

Between an exact solution and polynomial complexity

---

# Table of contents

- Presentation of the problem
- A few words about the problem
- Exact algorithms
  - Brute force
- Polynomial algorithms
  - Greedy distance remaining
  - Greedy proximity
  - Random
  - Static sorting
- Data used
- Results

---

# Presentation of the problem

![bg left:40% 80%](./pablo.png)

This is Pablo
Pablo wants to know the best way to grow his flour business.

![bg right:40% 80%](https://www.goway.com/media/uploads/maps/latin_america/colombia/colombia.jpg)

---

# A few words about the problem

- This is a NP-Complete problem
- It belongs to the group of optimization problems
- The challenge is to find the best solution with polynomial complexity
- The principle is to find the shortest circuit between n points, starting from a given point.

---

# Brute force

Description : Tries each possibility and calculates the distance, if it is less than the shortest distance already known then it defines this path as the shortest.
Complexity : $O(n*n!)$

```c
void permute(int start) {
    if (start > NB_CITIES-2) copy_path_to_min_path();
    for (int i = start; i < NB_CITIES-1; i++) {
        swap_path(start, i);
        permute(start+1);
        swap_path(start, i);
    }
}
void brute_force() {
    init_path();
    permute(0);
}
```

---

# Greedy distance remaining

Description : Choose the city closest to the remaining cities
Complexity : $\sum_{i=1}^{n}\sum_{j=1}^{n}1 + \sum_{i=1}^{n}(1 +\sum_{j=i+1}^{n}2) \le 3n^{2} = O(n^{2})$

```c
void greedy_distance_remaining() {
    init_path();
    couple array[NB_CITIES-1];
    /* Calculate the distance between cities */
    
    for (int i=0; i<NB_CITIES-1; i++) {
        couple min = {i, __INT_MAX__};
        for (int j=i; j<NB_CITIES-1; j++) if (array[j].y < min.y) {
            min.x = j; min.y = array[j].y;
        }
        swap_path(i, min.x); swap_couple(i, min.x, array);
        for (int j=i+1; j<NB_CITIES-1; j++)
            array[j].y -= distance_cities[path[i]][array[j].x];
    }
}
```

---

# Greedy proximity

Description : hoose the city closest to your current one
Complexity : $\sum_{i=1}^{n}\sum_{j=i}^{n}1 \le n^{2} = O(n^{2})$

```c
void greedy_proximity() {
    init_path();
    int actual_city = starting_city;
    for (int i=0; i<NB_CITIES-1; i++) {
        couple min = {i, __INT_MAX__};
        for (int j=i; j<NB_CITIES-1; j++)
            if (distance_cities[actual_city][path[j]] < min.y) {
                min.x = j;
                min.y = distance_cities[actual_city][path[j]];
        }
        swap_path(i, min.x);
        actual_city = path[i];
    }
    copy_path_to_min_path();
}
```

---

# Random

Description : Shuffle the list of cities and return it as a probable solution, probability $\ge \frac{2}{n!}$
Complexity : $O(n)$

```c
void shuffle() {
    init_path();
    srand(time(NULL));
    for (int i=0; i<NB_CITIES-1; i++)
        swap_path(rand() % (NB_CITIES-1), i);
    copy_path_to_min_path();
}
```

---

# Static sorting

Description : Sort cities by distance from starting city, using merge sort
Complexity : $O(n*log(n))$, cost of sorting


```c
void static_sort() {
    init_path();
    couple array[NB_CITIES-1];
    for (int i=0; i<NB_CITIES-1; i++) {
        couple c = {path[i], distance_cities[starting_city][path[i]]};
        array[i] = c;
    }
    merge_sort(array, 0, NB_CITIES-2);
    for(int i=0; i<NB_CITIES-1; i++) path[i] = array[i].x;
    copy_path_to_min_path();
}
```

---

# Useful functions

```c
void copy_path_to_min_path() {
    int dist =
        distance_cities[starting_city][path[0]]
        + distance_cities[path[NB_CITIES-2]][starting_city];
    for (int i=0; i<NB_CITIES-2; i++)
        dist += distance_cities[path[i]][path[i+1]];
    if (dist < min_path[0]) {
        min_path[0] = dist;
        for (int i=1; i<NB_CITIES; i++) min_path[i] = path[i-1];
    }
}
void init_path() {
    min_path[0] = __INT_MAX__;
    for (int i = 0; i < NB_CITIES-1; i++)
        path[i] = i + (i >= starting_city);
}
void swap_path(int i, int j) {
    int temp = path[i];
    path[i] = path[j];
    path[j] = temp;
}
```

---

# Data used

| | Armenia | Bogota | Cartagena | Neiva | San Agustin |
| - | - | - | - | - | - |
| **Armenia** | 0 | 177 | 652 | 184 | 303 |
| **Bogota** | 177 | 0 | 663 | 230 | 388 |
| **Cartagena** | 652 | 663 | 0 | 831 | 953 |
| **Neiva** | 184 | 230 | 831 | 0 | 159 |
| **San Agustin** | 303 | 388 | 953 | 159 | 0 |

---

# Results

All that remains is for Pablo to choose the method that suits him best

![bg left:40% 80%](./pablo.png)

Brute force : `Cartagena, Armenia, San Agustin, Neiva : 2007 km`
Greedy distance remaining : `Armenia, Neiva, San Agustin, Cartagena : 2136 km`
Greedy proximity : `Armenia, Neiva, San Agustin, Cartagena : 2136 km`
Random : `random`
Static sorting : `Armenia, Neiva, San Agustin, Cartagena : 2136 km`

---

Github : https://github.com/Angel-Karasu/traveling-salesman-problem