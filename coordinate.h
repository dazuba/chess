#pragma once
class Coordinate {
public:
    int x, y;

    Coordinate(int x, int y);

    Coordinate(const Coordinate& other);

    Coordinate& operator+=(const Coordinate& other);
    Coordinate& operator-=(const Coordinate& other);
    Coordinate operator+(const Coordinate& other) const;

    bool IsValid() const;
};