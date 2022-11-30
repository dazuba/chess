#pragma once

#include <vector>

#include "board.h"
#include "move.h"

class Game {
private:
    std::vector<Move> moves;
    Board board;

    void MakeMove(const Coordinate& crd1, const Coordinate& crd2);
};
