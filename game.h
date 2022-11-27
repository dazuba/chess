#include "board.h"
#include "move.h"
#include <vector>

class Game {
private:
    std::vector<Move> moves;
    Board board;

    void MakeMove(Coordinate crd1, Coordinate crd2);


};