
#include "Card.hpp"

Card::Card(SymbolTypes top, SymbolTypes right, SymbolTypes bottom, SymbolTypes left, int id)
{
    symbolPositions.push_back(top);
    symbolPositions.push_back(right);
    symbolPositions.push_back(bottom);
    symbolPositions.push_back(left);

    cardID = id;
}

void Card::rotateClockWise()
{
    std::rotate(symbolPositions.rbegin(), symbolPositions.rbegin() + 1, symbolPositions.rend());
    rotationCount++;
}

void Card::printPositions()
{
    for (auto &pos : symbolPositions)
        std::cout << pos << " ";
    std::cout << "\n";
}

SymbolTypes Card :: oppositeSymbol(SymbolTypes symbol)
{
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
