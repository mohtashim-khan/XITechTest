#include "header.hpp"

int main()
{
    //Part A
    std::vector<Card*> partA_args;

    partA_args.push_back(new Card(DOUBLEARROWBOTTOM, SINGLETRIANGLEBOTTOM, DOUBLETRIANGLETOP, SINGLEARROWTOP, 4));
    partA_args.push_back(new Card(DOUBLETRIANGLEBOTTOM, SINGLEARROWBOTTOM, DOUBLETRIANGLETOP, SINGLETRIANGLETOP, 5));
    partA_args.push_back(new Card(DOUBLETRIANGLETOP, DOUBLEARROWTOP, SINGLEARROWBOTTOM, DOUBLETRIANGLEBOTTOM, 6));
    partA_args.push_back(new Card(DOUBLETRIANGLEBOTTOM, DOUBLEARROWTOP, DOUBLETRIANGLETOP, SINGLEARROWBOTTOM, 7));



    Grid *partAGrid = new Grid(partA_args, 2);

    partAGrid->solve();






    //Part B
    std::vector<Card*> partB_args;

    partB_args.push_back(new Card(SINGLEARROWBOTTOM, DOUBLETRIANGLETOP, SINGLETRIANGLETOP, DOUBLEARROWBOTTOM, 1));
    partB_args.push_back(new Card(DOUBLEARROWBOTTOM, SINGLETRIANGLEBOTTOM, DOUBLEARROWTOP, SINGLEARROWTOP, 2));
    partB_args.push_back(new Card(DOUBLEARROWBOTTOM, SINGLETRIANGLEBOTTOM, DOUBLETRIANGLETOP, SINGLEARROWTOP, 3));
    partB_args.push_back(new Card(DOUBLEARROWBOTTOM, SINGLETRIANGLEBOTTOM, DOUBLETRIANGLETOP, SINGLEARROWTOP, 4));
    partB_args.push_back(new Card(DOUBLETRIANGLEBOTTOM, SINGLEARROWBOTTOM, DOUBLETRIANGLETOP, SINGLETRIANGLETOP, 5));
    partB_args.push_back(new Card(DOUBLETRIANGLETOP, DOUBLEARROWTOP, SINGLEARROWBOTTOM, DOUBLETRIANGLEBOTTOM, 6));
    partB_args.push_back(new Card(DOUBLETRIANGLEBOTTOM, DOUBLEARROWTOP, DOUBLETRIANGLETOP, SINGLEARROWBOTTOM, 7));
    partB_args.push_back(new Card(SINGLETRIANGLETOP, DOUBLEARROWTOP, SINGLETRIANGLETOP, SINGLEARROWBOTTOM, 8));
    partB_args.push_back(new Card(SINGLEARROWBOTTOM, DOUBLEARROWTOP, DOUBLETRIANGLETOP, SINGLETRIANGLEBOTTOM, 9));

    Grid *partBGrid = new Grid(partB_args, 3);

    partBGrid->solve();

    return EXIT_SUCCESS;




    
}