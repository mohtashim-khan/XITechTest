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
    void printGrid(std::vector<std::vector<Card*>> &grid);
    void incrementRowAndCol(int &row, int &col);
    void decrementRowAndCol(int &row, int &col);
    void addToGrid(Card *card, int row, int col, std::vector<std::vector<Card*>> &grid, std::unordered_set<Card*> &usedCards);
    void eraseFromGrid(Card *card, int row, int col, std::vector<std::vector<Card*>> &grid, std::unordered_set<Card*> &usedCards);
    void resetGrid(int &row, int &col, std::vector<std::vector<Card*>> &grid, std::unordered_set<Card*> &usedCards);
    void fillSymbolMap();
    void fillGrid(int row, int col, std::vector<std::vector<Card*>> grid, std::unordered_set<Card*> usedCards);
    bool insideCornersMatch(Card* currentCard, int row, int col, std::vector<std::vector<Card*>> &grid);
    std::set<Card*> findPotentialMatches(int row, int col, std::vector<std::vector<Card*>> &grid);
    std::set<Card *> setIntersection(std::set<Card*> &s1, std::set<Card*> &s2);

    int solutionCount = 0;
    int sideSize;
    int totalCards;
    std::unordered_map<SymbolTypes, std::set<Card*>> symbolMap;
    std::set<Card*> availableCards;
    
};

#endif