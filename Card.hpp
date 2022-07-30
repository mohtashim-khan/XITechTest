
#include "header.hpp"

#ifndef CARD_H
#define CARD_H


class Card;

enum SymbolTypes
{
    DOUBLETRIANGLETOP = 0,
    DOUBLETRIANGLEBOTTOM,
    SINGLETRIANGLETOP,
    SINGLETRIANGLEBOTTOM,
    DOUBLEARROWTOP,
    DOUBLEARROWBOTTOM,
    SINGLEARROWTOP,
    SINGLEARROWBOTTOM
};

enum Directions
{
    TOP = 0,
    RIGHT,
    BOTTOM,
    LEFT
};


class Card
{
    public:
    Card(){};

    Card(SymbolTypes top, SymbolTypes right, SymbolTypes bottom, SymbolTypes left, int id);

    void rotateClockWise(int n);

    void printPositions();

    void reset();

    SymbolTypes oppositeSymbol(Directions direction);


    std::vector<SymbolTypes> symbolPositions; //Top - 0, Right - 1, Bottom - 2, Left -3, Initial thoughts of using a map but then rotations would be difficult to do.
    int cardID;
    int rotationCount = 0;

    
};

#endif