
#include "Card.hpp"

Card::Card(SymbolTypes top, SymbolTypes right, SymbolTypes bottom, SymbolTypes left, int id)
{
    symbolPositions.push_back(top);
    symbolPositions.push_back(right);
    symbolPositions.push_back(bottom);
    symbolPositions.push_back(left);

    cardID = id;
}

/*
    Rotates Card clockwise by n times, also updates the symbol positions
*/
void Card::rotateClockWise(int n)
{
    while (n > 3)
        n -= 4;

    std::rotate(symbolPositions.rbegin(), symbolPositions.rbegin() + n, symbolPositions.rend());
    rotationCount += n;

    while (rotationCount > 3)
        rotationCount -= 4;
}
/*
    Resets Card to initial state by rotating anti-clockwise by rotation count
*/
void Card::reset()
{
    std::rotate(symbolPositions.begin(), symbolPositions.begin() + rotationCount, symbolPositions.end());
    rotationCount = 0;
}

void Card::printPositions()
{
    for (auto &pos : symbolPositions)
        std::cout << pos << " ";
    std::cout << "\n";
}
/*
    Returns the opposite Symbol (or Required symbol) for a given position in the card(TOP,LEFT,BOTTOM,RIGHT). 
    Useful for finding and verifying matching cards.
*/
SymbolTypes Card ::oppositeSymbol(Directions direction)
{

    SymbolTypes symbol = symbolPositions[direction];

    switch (symbol)
    {
    case DOUBLETRIANGLETOP:
        return DOUBLETRIANGLEBOTTOM;
        break;

    case DOUBLETRIANGLEBOTTOM:
        return DOUBLETRIANGLETOP;
        break;

    case SINGLETRIANGLETOP:
        return SINGLETRIANGLEBOTTOM;
        break;

    case SINGLETRIANGLEBOTTOM:
        return SINGLETRIANGLETOP;
        break;

    case DOUBLEARROWTOP:
        return DOUBLEARROWBOTTOM;
        break;

    case DOUBLEARROWBOTTOM:
        return DOUBLEARROWTOP;
        break;

    case SINGLEARROWTOP:
        return SINGLEARROWBOTTOM;
        break;

    case SINGLEARROWBOTTOM:
        return SINGLEARROWTOP;
        break;
    }

    return DOUBLEARROWBOTTOM;
}
