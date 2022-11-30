#include "pieces.h"

Piece::Piece(uint8_t color) : color_(color) {};

uint8_t Piece::GetColor() const {
    return color_;
}

MoveDirs King::Dirs() const {
    return MoveDirs {
        {
            Coordinate(0, 1),
            Coordinate(1, 1),
            Coordinate(1, 0),
            Coordinate(1, -1),
            Coordinate(0, -1),
            Coordinate(-1, -1),
            Coordinate(-1, 0),
            Coordinate(-1, 1)
        }, 
        1
    };
}

King::King(uint8_t color) {
    color_ = color;
}

MoveDirs Queen::Dirs() const {
    return MoveDirs {
        {
            Coordinate(0, 1),
            Coordinate(1, 1),
            Coordinate(1, 0),
            Coordinate(1, -1),
            Coordinate(0, -1),
            Coordinate(-1, -1),
            Coordinate(-1, 0),
            Coordinate(-1, 1)
        }, 
        7
    };
}

Queen::Queen(uint8_t color) {
    color_ = color;
}

MoveDirs Rook::Dirs() const {
    return MoveDirs {
        {
            Coordinate(0, 1),
            Coordinate(1, 0),
            Coordinate(0, -1),
            Coordinate(-1, 0)
        }, 
        7
    };
}

Rook::Rook(uint8_t color) {
    color_ = color;
}

MoveDirs Bishop::Dirs() const {
    return MoveDirs {
        {
            Coordinate(1, 1),
            Coordinate(1, -1),
            Coordinate(-1, -1),
            Coordinate(-1, 1)
        }, 
        7
    };
}

Bishop::Bishop(uint8_t color) {
    color_ = color;
}

MoveDirs Knight::Dirs() const {
    return MoveDirs {
        {
            Coordinate(1, 2),
            Coordinate(2, 1),
            Coordinate(2, -1),
            Coordinate(1, -2),
            Coordinate(-1, -2),
            Coordinate(-2, -1),
            Coordinate(-2, 1),
            Coordinate(-1, 2)
        }, 
        1
    };
}

Knight::Knight(uint8_t color) {
    color_ = color;
}

MoveDirs Pawn::Dirs() const {
    return MoveDirs { {}, 0 };
}

Pawn::Pawn(uint8_t color) {
    color_ = color;
}
