
#include "Card.hpp"

Card::Card(SymbolTypes top, SymbolTypes right, SymbolTypes bottom, SymbolTypes left, int id)
{
    symbolPositions.push_back(top);
    symbolPositions.push_back(right);
    symbolPositions.push_back(bottom);
    symbolPositions.push_back(left);

    cardID = id;
}