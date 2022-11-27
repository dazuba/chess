#pragma once
#include "coordinate.h"
#include "pieces.h"
#include <memory>

struct Move {
    Coordinate from, to;
    std::shared_ptr<Piece> piece;
};