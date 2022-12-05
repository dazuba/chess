#include "coordinate.h"

Coordinate::Coordinate(int8_t x, int8_t y) : x_(x), y_(y) {
}

Coordinate::Coordinate(const Coordinate& other) : x_(other.x_), y_(other.y_) {
}

Coordinate& Coordinate::operator+=(const Coordinate& other) {
    x_ += other.x_;
    y_ += other.y_;
    return *this;
}

Coordinate& Coordinate::operator-=(const Coordinate& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
}

Coordinate Coordinate::operator+(const Coordinate& other) const {
    return Coordinate(x_ + other.x_, y_ + other.y_);
}

Coordinate Coordinate::operator-(const Coordinate& other) const {
    return Coordinate(x_ - other.x_, y_ - other.y_);
}

bool Coordinate::operator==(const Coordinate& other) const {
    return x_ == other.x_ && y_ == other.y_;
}

bool Coordinate::IsValid() const {
    return x_ >= 0 && x_ < 8 && y_ >= 0 && y_ < 8;
}

size_t Coordinate::GetX() const {
    return x_;
}

size_t Coordinate::GetY() const {
    return y_;
}
