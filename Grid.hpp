#include "header.hpp"


#ifndef GRID_H
#define GRID_H


class Grid;

class Grid
{
    public:
    Grid() {};
    Grid(std::vector<Card*> &cards, int n);
    
    void print();
    void solve2D();
    void advanceCardPosition(int &rowIndex, int &colIndex);
    bool insideCornersMatch(int row, int col);



    int size;
    std::vector<std::vector<Card*>> grid;
    
};

#endif