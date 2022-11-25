#pragma once
#include "move.h"
#include "pieces.h"
#include "movedirs.h"
#include <vector>

class Board {
public:
    Piece* GetPiece(const Coordinate& crd) const;

private:
    std::vector<Move> moves;
    std::vector<std::vector<Piece*>> data_;

    std::vector<Coordinate> ValidMoves(const Coordinate& crd) const;
};