
#include "Card.hpp"

Card::Card(SymbolTypes top, SymbolTypes right, SymbolTypes bottom, SymbolTypes left, int id)
{
    symbolPositions.push_back(top);
    symbolPositions.push_back(right);
    symbolPositions.push_back(bottom);
    symbolPositions.push_back(left);

    cardID = id;
}

void Card::rotateClockWise(int n)
{
    while (n > 3)
    {
        n-=4;
    }

    std::rotate(symbolPositions.rbegin(), symbolPositions.rbegin() + n, symbolPositions.rend());
    rotationCount = (rotationCount >= 3) ? 0 : rotationCount+1;


}

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

SymbolTypes Card :: oppositeSymbol(Directions direction)
{

    SymbolTypes symbol = symbolPositions[direction];
    
    switch(symbol)
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
