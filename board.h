#pragma once
#include "move.h"
#include "pieces.h"
#include "movedirs.h"
#include <vector>
#include <memory>

class Board {
public:
    std::shared_ptr<Piece> GetPiece(const Coordinate& crd) const;

    bool MakeMove(const Coordinate& crd1, const Coordinate& crd2);

    std::vector<Coordinate> ValidMoves(const Coordinate& crd) const;

    bool IsValidMove(const Coordinate& crd1, const Coordinate& crd2) const;
    
    Coordinate FindKing(int color) const;

    bool IsCheck(int color) const;

    Board();

private:
    std::vector<std::vector<std::shared_ptr<Piece>>> data_;


};