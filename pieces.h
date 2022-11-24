#include "coordinate.h"
#include "vector"

class Piece {
protected:
    Coordinate crd;
    int color;

public:
    int GetColor();

    virtual std::vector<Coordinate> ValidMoves();

    virtual void move();
};

class King : Piece {
    inline static const std::vector<int> movex { 0, 1, 1, 1, 0, -1, -1, -1 };
    inline static const std::vector<int> movey { 1, 1, 0, -1, -1, -1, 0, 1 };
};

class Queen : Piece {

};

class Rook : Piece {

};

class Bishop : Piece {

};

class Knight : Piece {

};

class Pawn : Piece {

};