
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