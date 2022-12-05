#include "board.h"

#include <algorithm>
#include <exception>

namespace {
    
size_t GetColorRow(int8_t color) {
    return color * 7;
}

} // anonymous namespace

Board::Board() {
    data_ = std::vector<std::vector<std::shared_ptr<Piece>>>(
        BOARD_SIZE, std::vector<std::shared_ptr<Piece>>(BOARD_SIZE));
    for (int8_t color = 0; color <= 1; ++color) {
        data_[0][GetColorRow(color)] = std::make_shared<Rook>(color);
        data_[1][GetColorRow(color)] = std::make_shared<Knight>(color);
        data_[2][GetColorRow(color)] = std::make_shared<Bishop>(color);
        data_[3][GetColorRow(color)] = std::make_shared<Queen>(color);
        data_[4][GetColorRow(color)] = std::make_shared<King>(color);
        data_[5][GetColorRow(color)] = std::make_shared<Bishop>(color);
        data_[6][GetColorRow(color)] = std::make_shared<Knight>(color);
        data_[7][GetColorRow(color)] = std::make_shared<Rook>(color);
        for (size_t i = 0; i < BOARD_SIZE; ++i) {
            data_[i][GetColorRow(color) ^ 1] = std::make_shared<Pawn>(color);
        }
    }
}

bool Board::IsShortCastle(const Move& move) const {
    return std::dynamic_pointer_cast<King>((*this)[move.from]) != nullptr &&
        move.from + Coordinate(2, 0) == move.to;
}

bool Board::IsLongCastle(const Move& move) const {
    return std::dynamic_pointer_cast<King>((*this)[move.from]) != nullptr &&
        move.from + Coordinate(-2, 0) == move.to;
}

bool Board::CanShortCastle(const Coordinate& crd) const {
    const auto piece = (*this)[crd];
    if (std::dynamic_pointer_cast<King>(piece) != nullptr &&
        std::dynamic_pointer_cast<Rook>((*this)[crd + Coordinate(3, 0)]) != nullptr &&
        piece->GetFirstMove() == -1 &&
        (*this)[crd + Coordinate(3, 0)]->GetFirstMove() == -1 &&
        !IsCheck(piece->GetColor())) {
        for (size_t i = 1; i <= 2; ++i) {
            const auto newCrd = crd + Coordinate(i, 0);
            if ((*this)[newCrd] != nullptr || CheckForCheck({crd, newCrd})) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Board::CanLongCastle(const Coordinate& crd) const {
    const auto piece = (*this)[crd];
    if (std::dynamic_pointer_cast<King>(piece) != nullptr &&
        std::dynamic_pointer_cast<Rook>((*this)[crd + Coordinate(-4, 0)]) != nullptr &&
        piece->GetFirstMove() == -1 &&
        (*this)[crd + Coordinate(-4, 0)]->GetFirstMove() == -1 &&
        !IsCheck(piece->GetColor())) {
        for (size_t i = 1; i <= 3; ++i) {
            const auto newCrd = crd + Coordinate(-i, 0);
            if ((*this)[newCrd] != nullptr || CheckForCheck({crd, newCrd})) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Board::IsValidMove(const Move& move) const {
    std::vector<Coordinate> validMoves = ValidMoves(move.from);
    if (std::find(validMoves.begin(), validMoves.end(), move.to) == validMoves.end()) {
        return false;
    }

    Board boardCopy = *this;
    boardCopy.MakeMoveUnlocked(move);
    return boardCopy.IsCheck((*this)[move.from]->GetColor());
}

void Board::MakeMoveUnlocked(const Move& move) {
    std::swap((*this)[move.to], (*this)[move.from]);
    (*this)[move.from] = nullptr;
}

void Board::MakeMove(const Move& move) {
    if (!IsValidMove(move)) {
        throw std::runtime_error("Invalid move");
    }
    MakeMoveUnlocked(move);
    const auto piece = (*this)[move.to];
    if (piece->GetFirstMove() == -1) {
        piece->SetFirstMove(moveNum);
    }
    ++moveNum;
}

std::shared_ptr<Piece>& Board::operator[](const Coordinate& crd) {
    return data_[crd.GetX()][crd.GetY()];
}

const std::shared_ptr<Piece>& Board::operator[](const Coordinate& crd) const {
    return data_[crd.GetX()][crd.GetY()];
}

bool Board::CheckForCheck(const Move& move) const {
    Board boardCopy = *this;
    boardCopy.MakeMoveUnlocked(move);
    return boardCopy.IsCheck((*this)[move.from]->GetColor());
}

std::vector<Coordinate> Board::ValidMoves(const Coordinate& crd) const {
    MoveDirs dirs = (*this)[crd]->Dirs();
    int8_t color = (*this)[crd]->GetColor();
    std::vector<Coordinate> validMoves;

    if (std::dynamic_pointer_cast<Pawn>((*this)[crd]) != nullptr) {
        for (int i = 0; i < 2; i++) {
            if ((*this)[crd + dirs.dirs[i]] != nullptr && 
                (*this)[crd + dirs.dirs[i]]->GetColor() != color &&
                !CheckForCheck({crd, crd + dirs.dirs[i]})) {
                validMoves.push_back(crd + dirs.dirs[i]);
            }
            if (std::dynamic_pointer_cast<Pawn>((*this)[crd + Coordinate(dirs.dirs[i].GetX(), 0)]) != nullptr &&
                (*this)[crd + Coordinate(dirs.dirs[i].GetX(), 0)]->GetFirstMove() + 1 == moveNum &&
                crd.GetY() == static_cast<size_t>(4 - color)) {
                validMoves.push_back(crd + dirs.dirs[i]);
            }
        }
 
        if ((*this)[crd + dirs.dirs[2]] == nullptr &&
            !CheckForCheck({crd, crd + dirs.dirs[2]})) {
            validMoves.push_back(crd + dirs.dirs[2]);
        }

        if ((*this)[crd]->GetFirstMove() == -1 &&
            (*this)[crd + dirs.dirs[2]] == nullptr && 
            (*this)[crd + dirs.dirs[3]] == nullptr &&
            !CheckForCheck({crd, crd + dirs.dirs[2]})) {
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
            if (CheckForCheck({crd, curCrd})) {
                continue;
            }
            if ((*this)[curCrd] != nullptr) {
                int8_t otherColor = (*this)[curCrd]->GetColor();
                if (color != otherColor) {
                    validMoves.push_back(curCrd);
                }
                break;
            }
            validMoves.push_back(curCrd);
        }
    }

    if (std::dynamic_pointer_cast<King>((*this)[crd]) != nullptr) {
        
    }

    return validMoves;
}

Coordinate Board::FindKing(int8_t color) const {
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            if (dynamic_cast<King*>(data_[i][j].get()) != nullptr &&
                data_[i][j]->GetColor() == color) {
                return Coordinate(i, j);
            }
        }
    }
    throw std::runtime_error("No king on board(king wend mad)");
}

bool Board::IsCheck(int8_t color) const {
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

bool Board::IsStalemate(int8_t color) const {
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            if (data_[i][j]->GetColor() == color) {
                auto validMoves = ValidMoves(Coordinate(i, j));
                for (auto crd : validMoves) {
                    if (IsValidMove(Move{Coordinate(i, j), crd})) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool Board::IsCheckmate(int8_t color) const {
    return IsStalemate(color) && IsCheck(color);
}
