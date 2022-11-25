#include "pieces.h"

int Piece::GetColor() {
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

MoveDirs Pawn::Dirs() const {
    return MoveDirs { {}, 0 };
}