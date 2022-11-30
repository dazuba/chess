#pragma once

#include <cstddef>

class Coordinate {
public:
    Coordinate(size_t x, size_t y);
    Coordinate(const Coordinate& other);

    Coordinate& operator+=(const Coordinate& other);
    Coordinate& operator-=(const Coordinate& other);
    Coordinate operator+(const Coordinate& other) const;
    bool operator==(const Coordinate& other) const;

    bool IsValid() const;
    size_t GetX() const;
    size_t GetY() const;

private:
    size_t x_;
    size_t y_;
};
