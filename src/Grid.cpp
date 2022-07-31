#include "Grid.hpp"

Grid::Grid(std::set<Card *> &cards, int n)
{
    totalCards = n * n;
    if (cards.size() != totalCards)
    {
        std::cout << "# of cards != n*n therefore cannot make square grid \n";
        exit(EXIT_FAILURE);
    }
    sideSize = n;
    availableCards = cards;
    fillSymbolMap();
}

void Grid::printGrid(std::vector<std::vector<Card *>> &grid)
{
    solutionCount++;

    std::cout << "\n\n SOLUTION " << solutionCount << " : \n\n";

    for (auto &row : grid)
    {
        for (auto &card : row)
        {
            std::cout << "Card " << card->cardID;

            if (card->rotationCount > 0)
            {
                std::cout << "(Rotated Clockwise:" << card->rotationCount << ")";
            }

            std::cout << "\t";
        }

        std::cout << "\n";
    }
}

void Grid ::fillSymbolMap()
{
    for (auto &card : availableCards)
    {
        for (auto &symbol : card->symbolPositions)
        {
            symbolMap[symbol].insert(card);
        }
    }
}

bool Grid::insideCornersMatch(Card *currentCard, int row, int col, std::vector<std::vector<Card *>> &grid)
{
    Card *bottomCard = (row + 1 < grid.size()) ? grid[row + 1][col] : nullptr;
    Card *topCard = (0 <= row - 1) ? grid[row - 1][col] : nullptr;
    Card *leftCard = (0 <= col - 1) ? grid[row][col - 1] : nullptr;
    Card *rightCard = (col + 1 < grid[row].size()) ? grid[row][col + 1] : nullptr;

    if (topCard && topCard->oppositeSymbol(BOTTOM) != currentCard->symbolPositions[TOP])
        return false;

    if (bottomCard && bottomCard->oppositeSymbol(TOP) != currentCard->symbolPositions[BOTTOM])
        return false;

    if (leftCard && leftCard->oppositeSymbol(RIGHT) != currentCard->symbolPositions[LEFT])
        return false;

    if (rightCard && rightCard->oppositeSymbol(LEFT) != currentCard->symbolPositions[RIGHT])
        return false;

    return true;
}

std::set<Card *> Grid::findPotentialMatches(int row, int col, std::vector<std::vector<Card *>> &grid)
{
    Card *bottomCard = (row + 1 < grid.size()) ? grid[row + 1][col] : nullptr;
    Card *topCard = (0 <= row - 1) ? grid[row - 1][col] : nullptr;
    Card *leftCard = (0 <= col - 1) ? grid[row][col - 1] : nullptr;
    Card *rightCard = (col + 1 < grid[row].size()) ? grid[row][col + 1] : nullptr;

    std::set<Card *> topSet;
    std::set<Card *> leftSet;
    std::set<Card *> rightSet;
    std::set<Card *> bottomSet;
    std::set<Card *> resSet = availableCards;

    if (topCard)
    {
        topSet = symbolMap.at(topCard->oppositeSymbol(BOTTOM));
        resSet = setIntersection(topSet, resSet);
    }

    if (leftCard)
    {
        leftSet = symbolMap.at(leftCard->oppositeSymbol(RIGHT));
        resSet = setIntersection(leftSet, resSet);
    }

    if (rightCard)
    {
        rightSet = symbolMap.at(rightCard->oppositeSymbol(LEFT));
        resSet = setIntersection(rightSet, resSet);
    }

    if (bottomCard)
    {
        bottomSet = symbolMap.at(bottomCard->oppositeSymbol(TOP));
        resSet = setIntersection(bottomSet, resSet);
    }

    return resSet;
}

void Grid ::addToGrid(Card *card, int row, int col, std::vector<std::vector<Card *>> &grid, std::unordered_set<Card *> &usedCards)
{
    if (grid[row][col] != nullptr)
    {
        std::cerr << "ERROR: OVERWRITING ALREADY WRITTEN GRID POSITION at row: " << row << " col: " << col << "\n";
        exit(EXIT_FAILURE);
    }
    grid[row][col] = card;
    usedCards.insert(card);
}

void Grid ::eraseFromGrid(Card *card, int row, int col, std::vector<std::vector<Card *>> &grid, std::unordered_set<Card *> &usedCards)
{
    if (grid[row][col] == nullptr)
    {
        std::cerr << "ERROR: ERASING NULL PTR at row: " << row << " col: " << col << "\n";
        exit(EXIT_FAILURE);
    }
    grid[row][col]->reset();
    grid[row][col] = nullptr;
    usedCards.erase(card);
}

void Grid ::incrementRowAndCol(int &row, int &col)
{
    col++;
    if (col >= sideSize)
    {
        col = 0;
        row++;
        if (row >= sideSize)
            row = 0;
    }
}

void Grid ::decrementRowAndCol(int &row, int &col)
{
    col--;
    if (col < 0)
    {
        col = sideSize - 1;
        row--;
        if (row < 0)
            row = sideSize - 1;
    }
}

void Grid ::fillGrid(int row, int col, std::vector<std::vector<Card *>> grid, std::unordered_set<Card *> usedCards)
{

    if (usedCards.size() == totalCards) // If all cards are used then this is a valid solution, print out the output
    {
        printGrid(grid);
        return;
    }

    std::set<Card *> matches = findPotentialMatches(row, col, grid);

    for (auto &match : matches)
    {
        if (usedCards.find(match) != usedCards.end())
            continue;

        for (int matchRotation = 0; matchRotation < 4; matchRotation++)
        {
            match->rotateClockWise(matchRotation);

            if (insideCornersMatch(match, row, col, grid))
            {
                addToGrid(match, row, col, grid, usedCards);
                incrementRowAndCol(row, col);

                fillGrid(row, col, grid, usedCards);

                decrementRowAndCol(row, col);
                eraseFromGrid(match, row, col, grid, usedCards);
                break;
            }
        }
    }
}

std::set<Card *> Grid ::setIntersection(std::set<Card *> &s1, std::set<Card *> &s2)
{
    std::set<Card *> intersect;
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                          std::inserter(intersect, intersect.begin()));
    return intersect;
}

void Grid::resetCards()
{
    for(auto &card : availableCards)
        card->reset();
}

void Grid::solve()
{
    int row = 0;
    int col = 0;
    std::unordered_set<Card *> usedCards;
    std::vector<std::vector<Card *>> grid(sideSize, std::vector<Card *>(sideSize)); // Make empty nxn grid

    for (auto &card : availableCards)
    {
        for (int rotation = 0; rotation < 4; rotation++)
        {

            card->rotateClockWise(rotation);
            addToGrid(card, row, col, grid, usedCards);
            incrementRowAndCol(row, col);

            fillGrid(row, col, grid, usedCards);

            resetCards();
            decrementRowAndCol(row, col);
            eraseFromGrid(card, row, col, grid, usedCards);
        }
    }
}
