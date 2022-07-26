#include "Grid.hpp"

Grid::Grid(std::vector<Card*> &cards, int n)
{
    if (cards.size() != n * n)
    {
        std::cout << "# of cards != n*n therefore cannot make square grid \n";
        exit(EXIT_FAILURE);
    }

    int cardsCounter = 0;

    for (int i = 0; i < n; i++)
    {
        grid.push_back(std::vector<Card*>());

        for (int j = 0; j < n; j++)
        {
            grid[i].push_back(cards.at(cardsCounter));
            cardsCounter++;
        }
    }
}


void Grid::print()
{
    for (auto & row : grid)
    {
        for(auto &card : row)
        {
            std::cout << "Card " << card->cardID <<" ";

            if(card->rotationCount > 0)
            {
                std::cout << " Rotated Clockwise :" << card->rotationCount << " times ";
            }
        }

        std::cout<<"\n";

    }
}
