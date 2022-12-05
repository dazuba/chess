#include "pieces.h"

Piece::Piece(int8_t color) : color_(color) {}

int8_t Piece::GetColor() const {
    return color_;
}

void Piece::SetFirstMove(int32_t moveNum) {
    firstMove_ = moveNum;
}

int32_t Piece::GetFirstMove() const {
    return firstMove_;
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

King::King(int8_t color) : Piece(color) {
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

Queen::Queen(int8_t color) : Piece(color) {
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

Rook::Rook(int8_t color) : Piece(color) {
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

Bishop::Bishop(int8_t color) : Piece(color) {
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

Knight::Knight(int8_t color) : Piece(color) {
}

MoveDirs Pawn::Dirs() const {
    auto moveDirs = MoveDirs { 
        {
            Coordinate(-1, 1 - 2 * color_),
            Coordinate(1, 1 - 2 * color_),
            Coordinate(0, 1 - 2 * color_),
            Coordinate(0, 2 - 4 * color_)
        },
        1
    };
    
    return moveDirs;
}

Pawn::Pawn(int8_t color) : Piece(color) {
}
