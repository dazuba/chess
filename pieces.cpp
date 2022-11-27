#include "pieces.h"

Piece::Piece(int color) : color_(color) {};

int Piece::GetColor() const {
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

King::King(int color) {
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

Queen::Queen(int color) {
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

Rook::Rook(int color) {
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

Bishop::Bishop(int color) {
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

Knight::Knight(int color) {
    color_ = color;
}

MoveDirs Pawn::Dirs() const {
    return MoveDirs { {}, 0 };
}

Pawn::Pawn(int color) {
    color_ = color;
}