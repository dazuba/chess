#include "board.h"

Board::Board() {
    data_ = std::vector<std::vector<std::shared_ptr<Piece>>>(
        BOARD_SIZE, std::vector<std::shared_ptr<Piece>>(BOARD_SIZE));
    for (uint8_t color = 0; color < 2; ++color) {
        data_[0][color * 7] = (std::make_shared<Rook>(color));
        data_[1][color * 7] = (std::make_shared<Knight>(color));
        data_[2][color * 7] = (std::make_shared<Bishop>(color));
        data_[3][color * 7] = (std::make_shared<Queen>(color));
        data_[4][color * 7] = (std::make_shared<King>(color));
        data_[5][color * 7] = (std::make_shared<Bishop>(color));
        data_[6][color * 7] = (std::make_shared<Knight>(color));
        data_[7][color * 7] = (std::make_shared<Rook>(color));
        for (size_t i = 0; i < BOARD_SIZE; ++i) {
            data_[i][color * 5 + 1] =
                std::dynamic_pointer_cast<Piece>(std::make_shared<Pawn>(color));
        }
    }
}

bool Board::IsValidMove(const Coordinate& crd1, const Coordinate& crd2) const {
    std::vector<Coordinate> validMoves = ValidMoves(crd1);
    if (std::find(validMoves.begin(), validMoves.end(), crd2) == validMoves.end()) {
        return false;
    }

    Board boardCopy = *this;
    boardCopy.MakeMoveUnlocked(crd1, crd2);
    return boardCopy.IsCheck((*this)[crd1]->GetColor());
}

void Board::MakeMoveUnlocked(const Coordinate& crd1, const Coordinate& crd2) {
    (*this)[crd2] = (*this)[crd1];
    (*this)[crd1] = nullptr;
}

void Board::MakeMove(const Coordinate& crd1, const Coordinate& crd2) {
    if (!IsValidMove(crd1, crd2)) {
        // TODO throw exception
    }
    MakeMoveUnlocked(crd1, crd2);
    (*this)[crd2]->isMoved = true;
}

std::shared_ptr<Piece>& Board::operator[](const Coordinate& crd) {
    return data_[crd.GetX()][crd.GetY()];
}

const std::shared_ptr<Piece>& Board::operator[](const Coordinate& crd) const {
    return data_[crd.GetX()][crd.GetY()];
}

std::vector<Coordinate> Board::ValidMoves(const Coordinate& crd) const {
    MoveDirs dirs = GetPiece(crd)->Dirs();
    uint8_t color = GetPiece(crd)->GetColor();
    std::vector<Coordinate> validMoves;

    if (std::dynamic_pointer_cast<Pawn>((*this)[crd]) != nullptr) {
        for (int i = 0; i < 2; i++) {
            if ((*this)[crd + dirs.dirs[i]] != nullptr && 
                (*this)[crd + dirs.dirs[i]]->GetColor() != color) {
                validMoves.push_back(crd + dirs.dirs[i]);
            }
        }
 
        if ((*this)[crd + dirs.dirs[2]] == nullptr) {
            validMoves.push_back(crd + dirs.dirs[2]);
        }

        if (dirs.dirs.size() == 4 && (*this)[crd + dirs.dirs[2]] == nullptr && 
            (*this)[crd + dirs.dirs[3]] == nullptr) {
            validMoves.push_back(crd + dirs.dirs[2]);
        }

        return validMoves;
    }

    for (const auto& dir : dirs.dirs) {
        Coordinate curCrd = crd;
        for (uint8_t i = 0; i < dirs.steps; ++i) {
            curCrd += dir;
            if (!curCrd.IsValid()) {
                break;
            }
            if (GetPiece(curCrd) != nullptr) {
                uint8_t otherColor = GetPiece(curCrd)->GetColor();
                if (color != otherColor) {
                    validMoves.push_back(curCrd);
                }
                break;
            }
            validMoves.push_back(curCrd);
        }
    }

    if (std::dynamic_pointer_cast<King>((*this)[crd]) != nullptr) {
        if (!(*this)[crd]->isMoved) {
            
        }
    }

    return validMoves;
}

Coordinate Board::FindKing(uint8_t color) const {
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            if (dynamic_cast<King*>(data_[i][j].get()) != nullptr &&
                data_[i][j]->GetColor() == color) {
                return Coordinate(i, j);
            }
        }
    }
    // TODO exception
    return {__UINT32_MAX__, __UINT32_MAX__};
}

bool Board::IsCheck(uint8_t color) const {
    Coordinate kingCrd = FindKing(color);
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
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

bool Board::IsStalemate(uint8_t color) const {
    for (uint8_t i = 0; i < BOARD_SIZE; ++i) {
        for (uint8_t j = 0; j < BOARD_SIZE; ++j) {
            if (data_[i][j]->GetColor() == color) {
                auto validMoves = ValidMoves(Coordinate(i, j));
                for (auto crd : validMoves) {
                    if (IsValidMove(Coordinate(i, j), crd)) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool Board::IsCheckmate(uint8_t color) const {
    return IsStalemate(color) && IsCheck(color);
}
