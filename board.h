#pragma once
#include "move.h"
#include "pieces.h"
#include <vector>

class Board {
public:
    int GetPieceColor(const Coordinate& crd);

    // static Board& GetInstance();

private:
    std::vector<Move> moves;
    std::vector<std::vector<Piece>> data_;
    // static std::unique_ptr<Board> instance_;
    std::vector<Coordinate> ValidMoves(Coordinate crd) const;

    Board() = default;
};