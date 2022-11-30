#pragma once

#include <memory>
#include <vector>

#include "move.h"
#include "movedirs.h"
#include "pieces.h"

class Board {
public:
    Board();

    std::shared_ptr<Piece> GetPiece(const Coordinate& crd) const;

    std::vector<Coordinate> ValidMoves(const Coordinate& crd) const;

    bool IsValidMove(const Coordinate& crd1, const Coordinate& crd2) const;

    void MakeMove(const Coordinate& crd1, const Coordinate& crd2);

    Coordinate FindKing(uint8_t color) const;

    bool IsCheck(uint8_t color) const;

    bool IsCheckmate(uint8_t color) const;

    bool IsStalemate(uint8_t color) const;

    std::shared_ptr<Piece>& operator[](const Coordinate& crd);
    const std::shared_ptr<Piece>& operator[](const Coordinate& crd) const;

private:
    void MakeMoveUnlocked(const Coordinate& crd1, const Coordinate& crd2);

    static const size_t BOARD_SIZE = 8;

    std::vector<std::vector<std::shared_ptr<Piece>>> data_;
};
