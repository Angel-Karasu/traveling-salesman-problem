# Traveling Salesman Problem (TSP)

This is a simple project that uses various methods to find the (pseudo-)optimal path. Between having the right path and a path with a reduced complexity.

### Problem Description

The [Traveling Salesman Problem (TSP)](https://en.wikipedia.org/wiki/Travelling_salesman_problem) is a classic combinatorial optimization problem. The goal is to find the shortest possible route that visits each city exactly once and returns to the original city. It’s classified as an NP-hard problem in the field of combinatorial optimization.

- Given the city to start, a set of cities and the distances between them, find the optimal tour that minimizes the total distance traveled.
- Constraints: Each city must be visited exactly once, and the tour must return to the starting city.
 
### Approaches

1. Exact algorithms:
  - **Brute force:** Test all possibilties, `complexity = O(n*n!)`
2. Approximate algorithms:
  - **Greedy distance remaining:** Choose the city closest to the remaining cities, `complexity = O(n²)`
  - **Random:** Shuffle the list of cities and return it as a probable solution, `complexity = O(n)`
  - **Static sorting:** Sort cities by distance from starting city, using merge sort, `complexity = O(n*log(n))`

*n := number of cities to travel (number total of cities - 1)*
    
## Usage

If you want to test the project, clone this repository and compile it using make command
```shell
git clone https://github.com/Angel-Karasu/traveling-salesman-problem.git;
cd traveling-salesman-problem;
make all;
./path;
```
  
## License

This project is licensed under the [GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/).

See the `LICENSE` file for details.
