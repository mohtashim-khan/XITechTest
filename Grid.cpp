#include "Grid.hpp"

Grid::Grid(std::vector<Card *> &cards, int n)
{
    totalCards = n * n;
    if (cards.size() != totalCards)
    {
        std::cout << "# of cards != n*n therefore cannot make square grid \n";
        exit(EXIT_FAILURE);
    }

    grid = std::vector<std::vector<Card *>>(n, std::vector<Card *>(n)); // Make empty nxn grid.
    sideSize = n;
    availableCards = cards;
    fillSymbolMap();
}

void Grid::printGrid()
{
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
            symbolMap[symbol].push_back(card);
        }
    }
}

bool Grid::insideCornersMatch(Card *currentCard, int row, int col)
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

std::vector<Card *> Grid::findPotentialMatches(int row, int col)
{
    Card *bottomCard = (row + 1 < grid.size()) ? grid[row + 1][col] : nullptr;
    Card *topCard = (0 <= row - 1) ? grid[row - 1][col] : nullptr;
    Card *leftCard = (0 <= col - 1) ? grid[row][col - 1] : nullptr;
    Card *rightCard = (col + 1 < grid[row].size()) ? grid[row][col + 1] : nullptr;

    if (topCard)
    {
    }
}

void Grid ::addToGrid(Card *card, int row, int col)
{
    grid[row][col] = card;
    usedCards.insert(card);
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

void Grid ::resetGrid(int &row, int &col)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j])
                grid[i][j]->reset();

            grid[i][j] = nullptr;
        }
    }
    usedCards.clear();
    row = 0;
    col = 0;
}

void Grid ::fillGrid(int row, int col)
{
    if(usedCards.size() == totalCards)
        return;
    
    
    
    
    
    
    while (usedCards.size() != totalCards) // while all available cards are not used
    {
        std::vector<Card *> matches = findPotentialMatches();

        if (matches.empty())
            break;

        for (auto &match : matches)
        {

            for (int matchRotation = 0; matchRotation < 4; matchRotation++)
            {
                if (insideCornersMatch(match))
                {
                    addToGrid(match);
                    break;
                }

                match->rotateClockWise(1);
            }
        }
    }
}

/*
    For each available card in each rotation, add it as the main initial card which will be located at 0,0.
    After adding the main card, match the rest of the cards with the symbols on the main card in order, for example the next card will be added at 0,1 and will

*/
void Grid::solve()
{
    int row = 0;
    int col = 0;

    for (auto &card : availableCards)
    {
        for (int rotation = 0; rotation < 4; rotation++)
        {
            addToGrid(card, row, col);
            incrementRowAndCol(row, col);

            fillGrid(row, col);

            if (usedCards.size() == totalCards)
                printGrid();

            resetGrid(row, col);
            card->rotateClockWise(1);
        }

        resetGrid(row, col);
    }
}
