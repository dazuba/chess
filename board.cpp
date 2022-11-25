#include "board.h"

int Board::GetPieceColor(const Coordinate& crd) {
    return data_[crd.x][crd.y].GetPieceColor();
}

Square& Board::operator[](const Coordinate& crd) {
    return data_[crd.x][crd.y];
}

Board& Board::GetInstance() {
    if (!instance_) {
        instance_ = std::make_unique<Board>();
    }
    return *instance_;
}
