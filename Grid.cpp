#include "Grid.hpp"
#include <unordered_set>

Grid::Grid(std::vector<Card *> &cards, int n)
{
    if (cards.size() != n * n)
    {
        std::cout << "# of cards != n*n therefore cannot make square grid \n";
        exit(EXIT_FAILURE);
    }

    int cardsCounter = 0;

    for (int i = 0; i < n; i++)
    {
        grid.push_back(std::vector<Card *>());

        for (int j = 0; j < n; j++)
        {
            grid[i].push_back(cards[cardsCounter]);
            cardsCounter++;
        }
    }
}

void Grid::print()
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

void Grid ::advanceCardPosition(int &rowIndex, int &colIndex)
{
    int oldCol = colIndex;
    int oldRow = rowIndex;

    grid[rowIndex][colIndex]->rotationCount = 0; // reset Rotation count for card

    if (colIndex == grid[rowIndex].size() - 1)
    {
        colIndex = 0;

        if (rowIndex == grid.size() - 1)
            rowIndex = 0;
        else
            rowIndex++;
    }
    else
    {
        colIndex++;
    }

    std::swap(grid[oldRow][oldCol], grid[rowIndex][colIndex]);
}

bool Grid::insideCornersMatch(int row, int col)
{
    Card *currentCard = grid[row][col];
    Card *bottomCard = (row + 1 < grid.size()) ? grid[row + 1][col] : nullptr;
    Card *topCard = (0 <= row - 1) ? grid[row - 1][col] : nullptr;
    Card *leftCard = (0 <= col - 1) ? grid[row][col - 1] : nullptr;
    Card *rightCard = (col + 1 < grid[row].size()) ? grid[row][col + 1] : nullptr;

    if (topCard && topCard->symbolPositions[BOTTOM] != currentCard->symbolPositions[TOP])
        return false;

    if (bottomCard && bottomCard->symbolPositions[TOP] != currentCard->symbolPositions[BOTTOM])
        return false;

    if (leftCard && leftCard->symbolPositions[RIGHT] != currentCard->symbolPositions[LEFT])
        return false;

    if (rightCard && rightCard->symbolPositions[LEFT] != currentCard->symbolPositions[RIGHT])
        return false;

    return true;
}

/*

    Will have to check each block in every position and rotation to see if it is a valid solution,
    an effecient way to do this is to check the opposite inside corners for every position for the block to see if we can dismiss the position even before performing the rotations
    saving on 4 card rotations.

    In Order:

        -for a card in a position in the grid,
            -check opposite inside corners, if corners are matching
                -perform rotations on card and adding/printing any valid solutions

            -Swap card with the next card position.

        -keep repeating the above algo until all card positions are checked (total of 4! = 24 possible positions, we can check this by having the loop break when the set size == 24)

*/

void Grid::solve2D()
{
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[row].size(); col++)
        {
            int rowIndex = row;
            int colIndex = col;
            int advanceCount = 0;

            int oppositeRowIndex = (rowIndex == 0) ? 1 : 0;
            int oppositeColIndex = (colIndex == 0) ? 1 : 0;

            // Check Opposite Inside Corners
            while (!insideCornersMatch(oppositeRowIndex, oppositeColIndex) && advanceCount < 4)
            {
                advanceCardPosition(rowIndex, colIndex);
                advanceCount++;
            }

            // Perform Rotations
            if (advanceCount < 4)
            {
                // print if inside corners match and rotate
                for (int i = 0; i < 4; i++)
                {
                    if (insideCornersMatch(rowIndex, colIndex))
                        print();

                    grid[rowIndex][colIndex]->rotateClockWise();
                }
            }
        }
    }
}
