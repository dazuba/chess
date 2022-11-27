#pragma once
#include "movedirs.h"

class Piece {
protected:
    int color_;

public:
    Piece(int color);
    Piece() = default;

    int GetColor() const;

    virtual MoveDirs Dirs() const = 0;
};

class King : public Piece {
public:
    MoveDirs Dirs() const override;

    King(int color);
};

class Queen : public Piece {
public:
    MoveDirs Dirs() const override;

    Queen(int color);
};

class Rook : public Piece {
public:
    MoveDirs Dirs() const override;

    Rook(int color);
};

class Bishop : public Piece {
public:
    MoveDirs Dirs() const override;

    Bishop(int color);
};

class Knight : public Piece {
public:
    MoveDirs Dirs() const override;

    Knight(int color);
};

class Pawn : public Piece {
public:
    MoveDirs Dirs() const override;

    Pawn(int color);
};