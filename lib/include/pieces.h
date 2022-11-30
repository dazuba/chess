#pragma once

#include "movedirs.h"

class Piece {
protected:
    uint8_t color_;

public:
    Piece(uint8_t color);
    Piece() = default;
    virtual ~Piece() = default;

    uint8_t GetColor() const;

    virtual MoveDirs Dirs() const = 0;
};

class King : public Piece {
public:
    MoveDirs Dirs() const override;

    King(uint8_t color);
};

class Queen : public Piece {
public:
    MoveDirs Dirs() const override;

    Queen(uint8_t color);
};

class Rook : public Piece {
public:
    MoveDirs Dirs() const override;

    Rook(uint8_t color);
};

class Bishop : public Piece {
public:
    MoveDirs Dirs() const override;

    Bishop(uint8_t color);
};

class Knight : public Piece {
public:
    MoveDirs Dirs() const override;

    Knight(uint8_t color);
};

class Pawn : public Piece {
public:
    MoveDirs Dirs() const override;

    Pawn(uint8_t color);
};
