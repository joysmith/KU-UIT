
Simple Idea Behind the Code

Imagine:

- There are 10 cities on a map.

- A traveler wants to visit every city once and return home.

- But he wants to travel the shortest distance possible.

<br>

The computer:

1. Creates random cities.

2. Tries a random travel path.

3. Swaps cities to try new paths.

4. Keeps paths that are shorter.

5. Slowly becomes more careful while searching.

6. Finally finds a very short path.

This method is called Simulated Annealing, inspired by how hot metal cools slowly to become strong.

```py

# Import tools we need
from random import random      # to create random numbers
from random import shuffle     # to mix items randomly
import numpy as np             # for math calculations
from numpy.random import randint   # to generate random integers
import matplotlib.pyplot as plt    # to draw graphs


# A City is just a point on a map with x and y coordinates
class City:

    def __init__(self):
        # Pick a random position for the city on the map
        self.x = 1000 * random()   # horizontal position
        self.y = 1000 * random()   # vertical position

    # This helps print the city nicely like (x,y)
    def __repr__(self):
        return '(%s,%s)' % (round(self.x, 1), round(self.y, 1))


# A SingleTour means visiting all cities one by one
class SingleTour:

    def __init__(self):
        # This list will store all cities in order
        self.tour = []

    # Save a list of cities into the tour
    def set_tour(self, tour):
        self.tour.extend(tour)

    # Swap two cities in the list
    # This helps create a new possible path
    def swap(self, index1, index2):
        self.tour[index1], self.tour[index2] = self.tour[index2], self.tour[index1]

    # This function calculates the total distance of the tour
    # Smaller distance = better path
    def get_distance(self):
        tour_distance = 0

        # Go through each city and measure distance to next city
        for i in range(len(self.tour)):
            tour_distance += self.distance(self.tour[i % len(self.tour)],
                                           self.tour[(i + 1) % len(self.tour)])

        return tour_distance

    # Calculate distance between two cities
    @staticmethod
    def distance(city1, city2):

        # Find difference in x and y
        dist_x = abs(city1.x - city2.x)
        dist_y = abs(city1.y - city2.y)

        # Use math formula to calculate straight-line distance
        return np.sqrt(dist_x * dist_x + dist_y * dist_y)

    # Create random cities and mix them
    def generate_tour(self, n):
        for _ in range(n):
            self.tour.append(City())

        # Shuffle the order of cities
        shuffle(self.tour)

    # Return number of cities in the tour
    def get_tour_size(self):
        return len(self.tour)

    # Print all cities in the tour
    def __repr__(self):
        return ''.join(str(e) for e in self.tour)


# This class runs the Simulated Annealing algorithm
# It tries many paths and slowly improves them
class SimulatedAnnealing:

    # Setup the algorithm
    def __init__(self, num_cities, min_temp, max_temp, cooling_rate=0.01):
        self.num_cities = num_cities
        self.min_temp = min_temp
        self.max_temp = max_temp
        self.cooling_rate = cooling_rate

        # current path
        self.actual_state = SingleTour()

        # next possible path
        self.next_state = None

        # best path found so far
        self.best_state = None

    def run(self):

        # Create random cities and a starting path
        self.actual_state.generate_tour(self.num_cities)

        print('Initial (random) distance: %sm' % round(self.actual_state.get_distance(), 3))

        # Save first solution as best
        self.best_state = self.actual_state

        # Start with high temperature
        temp = self.max_temp

        # Keep searching until temperature becomes small
        while temp > self.min_temp:

            # Create a slightly different path
            new_state = self.generate_random_state(self.actual_state)

            # Calculate total distance for both paths
            actual_energy = self.actual_state.get_distance()
            new_energy = new_state.get_distance()

            # Decide if we should accept the new path
            if random() < self.accept_prob(actual_energy, new_energy, temp):

                # Save the new path as current
                single_tour = SingleTour()
                single_tour.set_tour(new_state.tour)
                self.actual_state = single_tour

            # If this path is the best so far, save it
            if self.actual_state.get_distance() < self.best_state.get_distance():
                single_tour = SingleTour()
                single_tour.set_tour(self.actual_state.tour)
                self.best_state = single_tour

            # Slowly reduce the temperature
            temp *= 1 - self.cooling_rate

        # Print the best distance found
        print('Solution: %sm' % round(self.best_state.get_distance(), 3))

    # Create a new path by swapping two cities
    @staticmethod
    def generate_random_state(actual_state):

        new_state = SingleTour()
        new_state.set_tour(actual_state.tour)

        # Pick two random cities
        random_index1 = randint(0, new_state.get_tour_size())
        random_index2 = randint(0, new_state.get_tour_size())

        # Swap their positions
        new_state.swap(random_index1, random_index2)

        return new_state

    # Draw the final solution on a graph
    def plot_solution(self):

        xs = []
        ys = []

        # Add first city again to close the path
        self.best_state.tour.append(self.best_state.tour[0])

        for city in self.best_state.tour:
            xs.append(city.x)
            ys.append(city.y)

        # Show city points
        plt.scatter(xs, ys)

        # Draw the path connecting them
        plt.plot(xs, ys)

        plt.show()

    # This decides the chance of accepting a worse solution
    @staticmethod
    def accept_prob(actual_energy, next_energy, temp):

        # If new path is better, always accept
        if next_energy < actual_energy:
            return 1

        # Otherwise accept with some probability
        return np.exp((actual_energy - next_energy) / temp)


# Start the program
if __name__ == '__main__':

    # Create algorithm with 10 cities
    algorithm = SimulatedAnnealing(10, 1e-5, 100000)

    # Run the search
    algorithm.run()

    # Show the best path found
    algorithm.plot_solution()
```


Challenges:(Any 15)

## Beginner Level

1. Modify the code to print only the x coordinate of each city.
1. Modify the code to print only the y coordinate of each city.
1. Print all cities with numbering: City 1 → (x,y)
1. Print only the first 5 cities.
1. Print cities in reverse order.
1. Count and print how many cities have x > 500.
1. Count and print how many cities have y < 500.
1. Find and print the city with maximum x value.
1. Find and print the city with minimum y value.
1. Modify code to print the initial random tour distance clearly.
1. Print the tour before shuffle and after shuffle.
1. Print index numbers with cities: 0 → (x,y)
1. Print distance between the first and last city only.
1. Print distance between every pair of cities in the tour.
1. Modify get_distance() to show step-by-step distance calculation.
1. Add a counter to print how many iterations the algorithm runs.
1. Add a counter to print total number of swaps performed.
1. Print whenever a better solution is found.
1. Print temperature after every 50 iterations.
1. Store all intermediate distances in a list and print it at the end.

## Medium Level 

1. Modify stopping condition to run for fixed 500 iterations instead of temperature.
1. Modify swap logic to swap only neighbor cities (i and i+1).
1. Modify swap logic to swap first and last cities only.
1. Modify code to swap cities only if index difference > 2.
1. Modify acceptance rule to accept only better solutions (remove probability).
1. Run algorithm 3 times and print all final distances.
1. Find and print the best result among 3 runs.
1. Modify code to take number of cities from user input.
1. Change cooling rate to 0.1 and 0.001 and compare results.
1. Print how much the distance improved from start to final solution.


## Graph color


1. Use different colors for cities and path (e.g., yellow + purple).
1. Change marker style of cities (e.g., 'o', 'x', '*').
1. Add title to graph:"Best Path Found"
1. Add axis labels: "X Coordinate" and "Y Coordinate"
1. Add grid to graph using plt.grid().
1. Highlight starting city in a different color (e.g., red).
1. Highlight ending city in another color (e.g., orange).
1. Show city index numbers near each point using plt.text().
1. Color cities differently based on condition: if x > 500 → red, else blue
1. Change path color based on distance (short = green, long = red).
1. Use random color each time graph is plotted.
1. Create a gradient color path (advanced).
1. Animate path drawing step-by-step (use loop + pause).
1. Plot initial path and final path in different colors.
1. Add legend explaining colors (start, end, path, cities).
