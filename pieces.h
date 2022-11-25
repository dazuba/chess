#pragma once
#include "movedirs.h"

class Piece {
protected:
    int color_;

public:
    int GetColor();

    virtual MoveDirs Dirs() const = 0;
};

class King : Piece {
public:
    MoveDirs Dirs() const override;
};

class Queen : Piece {
public:
    MoveDirs Dirs() const override;
};

class Rook : Piece {
public:
    MoveDirs Dirs() const override;
};

class Bishop : Piece {
public:
    MoveDirs Dirs() const override;
};

class Knight : Piece {
public:
    MoveDirs Dirs() const override;
};

class Pawn : Piece {
public:
    MoveDirs Dirs() const override;
};