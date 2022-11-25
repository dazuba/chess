#include "coordinate.h"
#include "vector"

class Piece {
protected:
    Coordinate crd_;
    int color_;

    void ValidMoveVec(Coordinate moveVec, std::vector<Coordinate>& ans) const;

public:
    int GetColor();

    virtual std::vector<Coordinate> ValidMoves() const = 0;
};

class King : Piece {
private:
    inline static const std::vector<Coordinate> move { 
        Coordinate(0, 1),
        Coordinate(1, 1),
        Coordinate(1, 0),
        Coordinate(1, -1),
        Coordinate(0, -1),
        Coordinate(-1, -1),
        Coordinate(-1, 0),
        Coordinate(-1, 1)};

public:
    std::vector<Coordinate> ValidMoves() const override;
};

class Queen : Piece {
public:
    std::vector<Coordinate> ValidMoves() const override;
};

class Rook : Piece {
public:
    std::vector<Coordinate> ValidMoves() const override;
};

class Bishop : Piece {
public:
    std::vector<Coordinate> ValidMoves() const override;
};

class Knight : Piece {
private:
    inline static const std::vector<Coordinate> move { 
        Coordinate(1, 2),
        Coordinate(2, 1),
        Coordinate(2, -1),
        Coordinate(1, -2),
        Coordinate(-1, -2),
        Coordinate(-2, -1),
        Coordinate(-2, 1),
        Coordinate(-1, 2)};

public:
    std::vector<Coordinate> ValidMoves() const override;
};

class Pawn : Piece {
public:
    std::vector<Coordinate> ValidMoves() const override;
};