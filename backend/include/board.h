#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "move.h"
#include "movedirs.h"
#include "pieces.h"

class Board {
public:
    Board();

    std::vector<Coordinate> ValidMoves(const Coordinate& crd) const;

    void MakeMove(const Move& move);

    bool IsCheck(int8_t color) const;

    bool IsCheckmate(int8_t color) const;

    bool IsStalemate(int8_t color) const;

    std::shared_ptr<Piece>& operator[](const Coordinate& crd);
    const std::shared_ptr<Piece>& operator[](const Coordinate& crd) const;

    static const size_t BOARD_SIZE = 8;

    int32_t GetMoveNum() const;

    int8_t GetStepColor() const;

private:
    void MakeMoveUnlocked(const Move& move);

    void SetFirstMove(const Coordinate& crd) const;

    Coordinate FindKing(int8_t color) const;

    bool IsValidMove(const Move& move) const;
    bool CheckForCheck(const Move& move) const;
    std::vector<Coordinate> AttackedSquares(const Coordinate& crd) const;

    bool IsShortCastle(const Move& move) const;
    bool IsLongCastle(const Move& move) const;

    bool CanShortCastle(const Coordinate& crd) const;
    bool CanLongCastle(const Coordinate& crd) const;

    std::vector<std::vector<std::shared_ptr<Piece>>> data_;

    int32_t moveNum = 0;
};
