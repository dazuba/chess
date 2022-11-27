#include "board.h"
#include <memory>

Board::Board() {
    data_ = std::vector<std::vector<std::shared_ptr<Piece>>>(8, std::vector<std::shared_ptr<Piece>>(8));
    for (int color = 0; color < 2; ++color) {
        data_[0][color * 7] = (std::make_shared<Rook>(color));
        data_[1][color * 7] = (std::make_shared<Knight>(color));
        data_[2][color * 7] = (std::make_shared<Bishop>(color));
        data_[3][color * 7] = (std::make_shared<Queen>(color));
        data_[4][color * 7] = (std::make_shared<King>(color));
        data_[5][color * 7] = (std::make_shared<Bishop>(color));
        data_[6][color * 7] = (std::make_shared<Knight>(color));
        data_[7][color * 7] = (std::make_shared<Rook>(color));
        for (int i = 0; i < 8; ++i) {
            data_[i][color * 5 + 1] = std::dynamic_pointer_cast<Piece>(std::make_shared<Pawn>(color));;
        }
    }
}

bool Board::IsValidMove(const Coordinate& crd1, const Coordinate& crd2) const {
    std::vector<Coordinate> validMoves = ValidMoves(crd1);
    if (std::find(validMoves.begin(), validMoves.end(), crd2) != validMoves.end()) {
        return true;
    }
    return false;
}

bool Board::MakeMove(const Coordinate& crd1, const Coordinate& crd2) {
    if (!IsValidMove(crd1, crd2)) {
        return false; 
    }

    std::shared_ptr<Piece> eaten = GetPiece(crd2);
    data_[crd2.x][crd2.y] = data_[crd1.x][crd1.y];

    if (IsCheck(GetPiece(crd2)->GetColor())) {
        data_[crd1.x][crd1.y] = data_[crd2.x][crd2.y];
        data_[crd2.x][crd2.y] = eaten;
        return false;
    }

    return true;
}

std::shared_ptr<Piece> Board::GetPiece(const Coordinate& crd) const {
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

Coordinate Board::FindKing(int color) const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (dynamic_cast<King*>(data_[i][j].get()) != nullptr && data_[i][j]->GetColor() == color) {
                return Coordinate(i, j);
            }
        }
    }
    // TODO exception
}

bool Board::IsCheck(int color) const {
    Coordinate kingCrd = FindKing(color);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (data_[i][j] != nullptr && data_[i][j]->GetColor() != color) {
                std::vector<Coordinate> validMoves = ValidMoves(Coordinate(i, j));
                if (std::find(validMoves.begin(), validMoves.end(), kingCrd) != validMoves.end()) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Piece*& Board::operator[](const Coordinate& c) {
//     return data_[c.i][c.j];
// }

// bool Board::IsCheckmate(int color) const {
//     for (int i = 0; i < 8; ++i) {
//         for (int j = 0; j < 8; ++j) {

//         }
//     }
// }