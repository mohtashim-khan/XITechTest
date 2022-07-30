#include "header.hpp"
#include <unordered_map>
#include <unordered_set>

#ifndef GRID_H
#define GRID_H


class Grid;

class Grid
{
    public:
    Grid() {};
    Grid(std::vector<Card*> &cards, int n);
    
    void printGrid();
    void solve();
    void incrementRowAndCol(int &row, int &col);
    void addToGrid(Card *card, int row, int col);
    void resetGrid(int &row, int &col);
    void fillSymbolMap();
    void fillGrid(int row, int col);
    bool insideCornersMatch(Card* currentCard, int row, int col);
    std::vector<Card*> findPotentialMatches(int row, int col);



    int sideSize;
    int totalCards;
    std::unordered_set<Card*> usedCards;
    std::unordered_map<SymbolTypes, std::vector<Card*>> symbolMap;
    std::vector<Card*> availableCards;
    std::vector<std::vector<Card*>> grid;
    
};

#endif