#pragma once

#include <string>

#include "movedirs.h"

class Piece {
public:
    explicit Piece(int8_t color);
    virtual ~Piece() = default;

    int8_t GetColor() const;

    virtual MoveDirs Dirs() const = 0;

    void SetFirstMove(int32_t moveNum);
    int32_t GetFirstMove() const;

    virtual std::string GetName() const = 0;

protected:
    const int8_t color_;

private:
    int32_t firstMove_ = -1;
};

class King : public Piece {
public:
    MoveDirs Dirs() const override;

    King(int8_t color);

    std::string GetName() const override;
};

class Queen : public Piece {
public:
    MoveDirs Dirs() const override;

    Queen(int8_t color);

    std::string GetName() const override;
};

class Rook : public Piece {
public:
    MoveDirs Dirs() const override;

    Rook(int8_t color);

    std::string GetName() const override;
};

class Bishop : public Piece {
public:
    MoveDirs Dirs() const override;

    Bishop(int8_t color);

    std::string GetName() const override;
};

class Knight : public Piece {
public:
    MoveDirs Dirs() const override;

    Knight(int8_t color);

    std::string GetName() const override;
};

class Pawn : public Piece {
public:
    MoveDirs Dirs() const override;

    Pawn(int8_t color);

    std::string GetName() const override;
};
