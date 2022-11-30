#pragma once

#include <memory>

#include "coordinate.h"
#include "pieces.h"

struct Move {
    Coordinate from, to;
    std::shared_ptr<Piece> piece;
};
