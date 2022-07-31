#include "header.hpp"
#include <unordered_map>
#include <unordered_set>
#include <set>

#ifndef GRID_H
#define GRID_H


class Grid;

class Grid
{
    public:
    Grid() {};
    Grid(std::set<Card*> &cards, int n);
    void solve();


    private:
    void printGrid();
    void incrementRowAndCol(int &row, int &col);
    void addToGrid(Card *card, int row, int col);
    void resetGrid(int &row, int &col);
    void fillSymbolMap();
    void fillGrid(int row, int col);
    bool insideCornersMatch(Card* currentCard, int row, int col);
    std::set<Card*> findPotentialMatches(int row, int col);
    std::set<Card *> setIntersection(std::set<Card*> &s1, std::set<Card*> &s2);



    int sideSize;
    int totalCards;
    std::unordered_set<Card*> usedCards;
    std::unordered_map<SymbolTypes, std::set<Card*>> symbolMap;
    std::set<Card*> availableCards;
    std::vector<std::vector<Card*>> grid;
    
};

#endif