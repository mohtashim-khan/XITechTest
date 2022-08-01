# Tech Test

## Build and Run Instructions

- Program utilizes CMake, to build use command : cmake --build build
- To run, use command : ./build/TechTest

- I can also send the executable via email if need be, or release it here
## Design General Overview

When tackling this problem, I wanted to create an algorithm that could be used for any NxN grid and was efficient enough to return ALL the correct results almost instantly. I was able to achieve this through the smart use of maps, sets, and recursion. The major problem with this challenge was the sheer amount of possible card positions and rotations there were and to figure out a way to find the solutions without brute forcing the algorithm.

There are two classes defined in the program, a Card class for representing the individual cards and a Grid class for representing the NxN grid. The Card class defines an individual card by recording it's identifier, symbol positions, and how many times it has been rotated clockwise. The Card class also contains various enums and helper functions related to manipulating a single card. 

The Grid class represents the NxN problem that needs to be solved. The Grid class has a member vector that keeps track of all the cards available to the problem, a symbol map to map each card symbol to a set of cards that contain that symbol to allow for easy matching of cards, the size of the grid, and it also keeps track of the amount of solutions that have been found. The class contains various helper functions as well as the solve() and fillGrid() functions that are discussed below.

## Solving The Grid
### solve()
 The solve() function initializes an empty grid of NxN then for each available card inserts the card into the first position then calls the fillGrid() recursive function. After calling the fillGrid() function, it then removes the inserted card from the grid, rotates it, then places it back into the grid and calls the fillGrid() function again. This way all initial states are covered by the solution and the fillGrid() function can handle the rest.

### fillGrid()
The fillGrid() function as the name implies, is a recursive function that fills the rest of the grid based on a current grid condition. The way it does this is by calling the findPotentialMatches() function which matches the existing symbols on the grid for a given position with a set of matching Cards that have the required symbols on them (via the symbol map). Then for each matching card, it then rotates the card until all inner edges of the current grid are valid (verified using the insideCornersMatch() function), after which it adds the card to the grid and does a recursive call to fillGrid() for the next empty position in the grid. If all positions are filled in the grid, it would then know its a valid solution and prints out the output. If no matches are found for a given position, it would simply return and do nothing.

## Solutions

The following solutions are found when the program is run, the run-time of the program is less than a second:

    ****** PART A: ******



    SOLUTION 1 : 

    Card 4(Rotated Clockwise:2)     Card 5(Rotated Clockwise:2)
    Card 7(Rotated Clockwise:3)     Card 6


    SOLUTION 2 : 

    Card 5(Rotated Clockwise:1)     Card 6(Rotated Clockwise:3)
    Card 4(Rotated Clockwise:1)     Card 7(Rotated Clockwise:2)


    SOLUTION 3 : 

    Card 6(Rotated Clockwise:2)     Card 7(Rotated Clockwise:1)
    Card 5  Card 4


    SOLUTION 4 : 

    Card 7  Card 4(Rotated Clockwise:3)
    Card 6(Rotated Clockwise:1)     Card 5(Rotated Clockwise:3)


    ****** PART B: ******



    SOLUTION 1 : 

    Card 9(Rotated Clockwise:3)     Card 7(Rotated Clockwise:3)     Card 6
    Card 5(Rotated Clockwise:1)     Card 4(Rotated Clockwise:1)     Card 2(Rotated Clockwise:1)
    Card 3(Rotated Clockwise:1)     Card 1(Rotated Clockwise:2)     Card 8(Rotated Clockwise:2)


    SOLUTION 2 : 

    Card 1(Rotated Clockwise:3)     Card 2(Rotated Clockwise:2)     Card 8
    Card 9(Rotated Clockwise:3)     Card 7(Rotated Clockwise:3)     Card 3(Rotated Clockwise:3)
    Card 5(Rotated Clockwise:1)     Card 4(Rotated Clockwise:1)     Card 6(Rotated Clockwise:2)


    SOLUTION 3 : 

    Card 6  Card 4(Rotated Clockwise:3)     Card 5(Rotated Clockwise:3)
    Card 3(Rotated Clockwise:1)     Card 7(Rotated Clockwise:1)     Card 9(Rotated Clockwise:1)
    Card 8(Rotated Clockwise:2)     Card 2  Card 1(Rotated Clockwise:1)


    SOLUTION 4 : 

    Card 6(Rotated Clockwise:3)     Card 2  Card 8(Rotated Clockwise:1)
    Card 7(Rotated Clockwise:2)     Card 4  Card 1(Rotated Clockwise:1)
    Card 9(Rotated Clockwise:2)     Card 5  Card 3


    SOLUTION 5 : 

    Card 8  Card 1  Card 3(Rotated Clockwise:3)
    Card 2(Rotated Clockwise:3)     Card 4(Rotated Clockwise:3)     Card 5(Rotated Clockwise:3)
    Card 6(Rotated Clockwise:2)     Card 7(Rotated Clockwise:1)     Card 9(Rotated Clockwise:1)


    SOLUTION 6 : 

    Card 8(Rotated Clockwise:3)     Card 3(Rotated Clockwise:2)     Card 6(Rotated Clockwise:1)
    Card 2(Rotated Clockwise:1)     Card 7(Rotated Clockwise:2)     Card 4
    Card 1(Rotated Clockwise:2)     Card 9(Rotated Clockwise:2)     Card 5


    SOLUTION 7 : 

    Card 3(Rotated Clockwise:2)     Card 5(Rotated Clockwise:2)     Card 9
    Card 1(Rotated Clockwise:3)     Card 4(Rotated Clockwise:2)     Card 7
    Card 8(Rotated Clockwise:3)     Card 2(Rotated Clockwise:2)     Card 6(Rotated Clockwise:1)


    SOLUTION 8 : 

    Card 5(Rotated Clockwise:2)     Card 9  Card 1
    Card 4(Rotated Clockwise:2)     Card 7  Card 2(Rotated Clockwise:3)
    Card 6(Rotated Clockwise:3)     Card 3  Card 8(Rotated Clockwise:1)



