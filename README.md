# Traveling Salesman Problem (TSP)

This is a simple project that uses various methods to find the (pseudo-)optimal solution for the TSP. Between having the right path and a path with a reduced complexity.

### Problem Description

The [Traveling Salesman Problem (TSP)](https://en.wikipedia.org/wiki/Travelling_salesman_problem) is a classic combinatorial optimization problem. The goal is to find the shortest possible route that visits each point exactly once and returns to the starting point. It’s classified as an NP-hard problem in the field of combinatorial optimization.

- Given the point to start, a set of cities and the distances between them, find the optimal tour that minimizes the total distance traveled.
- Constraints: Each point must be visited exactly once, and the tour must return to the starting point.
 
## Approaches

1. Exact algorithms:
    - **Exhaustive search:** Test all possibilties, $complexity = O((n+1)!)$
2. Approximate algorithms:
    - **Greedy distance remaining:** Choose the point closest to the remaining cities, $complexity = O(n²)$
    - **Greedy proximity:** Choose the point closest to your current one, $complexity = O(n²)$
    - **Random:** Shuffle the list of cities and return it as a probable solution, $complexity = O(n)$
    - **Static sorting:** Sort cities by distance from starting point, using merge sort, $complexity = O(nlog(n))$

*n := number of cities to travel (number total of cities - 1)*
    
## Installation

Clone this repository and compile it using make command
```shell
git clone https://codeberg.org/Angel-Karasu/traveling-salesman-problem.git;
cd traveling-salesman-problem;
make all;
```

## How to use

1. Run the executable file : `path`
2. Choose the starting point

## To do

- [ ] Optimized exhaustive search
- [ ] Add more algorithms
- [ ] Stylish the marp slides
  
## License

This project is licensed under the [GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/).

See the `LICENSE` file for details.
