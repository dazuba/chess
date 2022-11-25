#include "board.h"

Piece* Board::GetPiece(const Coordinate& crd) const {
    return data_[crd.x][crd.y];
}

std::vector<Coordinate> Board::ValidMoves(const Coordinate& crd) const {
    MoveDirs dirs = GetPiece(crd)->Dirs();
    int color = GetPiece(crd)->GetColor();
    std::vector<Coordinate> validMoves;
    
    if (dirs.steps == 0) {
        // пешка ходить не будет
        return validMoves;
    }

    for (auto dir : dirs.dirs) {
        Coordinate curCrd = crd;
        for (int i = 0; i < dirs.steps; ++i) {
            curCrd += dir;
            if (!curCrd.IsValid()) {
                break;
            }
            if (GetPiece(curCrd) != nullptr) {
                int otherColor = GetPiece(curCrd)->GetColor();
                if (color != otherColor) {
                    validMoves.push_back(curCrd);
                }
                break;
            }
            validMoves.push_back(curCrd);
        }
    }

    return validMoves;
}