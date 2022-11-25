#pragma once
#include <vector>
#include "square.h"
#include "move.h"

class Board {
public:
    int GetPieceColor(const Coordinate& crd);

    static Board& GetInstance();

    

    Square& operator[](const Coordinate& crd);

private:
    std::vector<Move> moves;
    std::vector<std::vector<Square>> data_;
    static std::unique_ptr<Board> instance_;

    Board() = default;
};