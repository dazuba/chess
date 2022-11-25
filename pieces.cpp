#include "pieces.h"
#include "board.h"

int Piece::GetColor() {
    return color_;
}

void Piece::ValidMoveVec(Coordinate moveVec, std::vector<Coordinate>& ans) const {
    Coordinate crd = crd_ + moveVec;
    auto board = Board::GetInstance();
    while (crd.x >= 0 && crd.x < 8 && crd.y >= 0 && crd.y < 8) {
        int otherColor = board[crd].GetPieceColor();
        if (otherColor == 0) {
            ans.push_back(crd);
        }
        else if (otherColor == color_) {
            break;
        }
        else {
            ans.push_back(crd);
            break;
        }
        crd += moveVec;
    }
}

std::vector<Coordinate> Queen::ValidMoves() const {
    std::vector<Coordinate> ans;

    ValidMoveVec(Coordinate(0, 1), ans);
    ValidMoveVec(Coordinate(1, 1), ans);
    ValidMoveVec(Coordinate(1, 0), ans);
    ValidMoveVec(Coordinate(1, -1), ans);
    ValidMoveVec(Coordinate(0, -1), ans);
    ValidMoveVec(Coordinate(-1, -1), ans);
    ValidMoveVec(Coordinate(-1, 0), ans);
    ValidMoveVec(Coordinate(-1, 1), ans);

    return ans;
}

std::vector<Coordinate> Rook::ValidMoves() const {
    std::vector<Coordinate> ans;

    ValidMoveVec(Coordinate(0, 1), ans);
    ValidMoveVec(Coordinate(1, 0), ans);
    ValidMoveVec(Coordinate(0, -1), ans);
    ValidMoveVec(Coordinate(-1, 0), ans);

    return ans;
}

std::vector<Coordinate> Bishop::ValidMoves() const {
    std::vector<Coordinate> ans;

    ValidMoveVec(Coordinate(1, 1), ans);
    ValidMoveVec(Coordinate(1, -1), ans);
    ValidMoveVec(Coordinate(-1, -1), ans);
    ValidMoveVec(Coordinate(-1, 1), ans);

    return ans;
}

std::vector<Coordinate> Knight::ValidMoves() const {
    std::vector<Coordinate> ans;
    Coordinate crd = crd_;
    auto board = Board::GetInstance();
    for (int i = 0; i < 8; i++) {
        crd += move[i];

        if (crd.x >= 0 && crd.x < 8 && crd.y >= 0 && crd.y < 8) {
            int otherColor = board.GetPieceColor(crd);
            if (color_ != otherColor) {
                ans.push_back(crd);
            }
        }

        crd -= move[i];
    }

    return ans;
}

std::vector<Coordinate> Pawn::ValidMoves() const {
    std::vector<Coordinate> ans;
    auto board = Board::GetInstance();

    if (board.GetPieceColor(crd_ + Coordinate(0, 1)) == 0) {
        ans.push_back(crd_ + Coordinate(0, 1));
    }

    if (board.GetPieceColor(crd_ + Coordinate(1, 1)) != color_) {
        ans.push_back(crd_ + Coordinate(1, 1));
    }

    if (board.GetPieceColor(crd_ + Coordinate(1, -1)) != color_) {
        ans.push_back(crd_ + Coordinate(1, -1));
    }
}