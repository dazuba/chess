#include "pieces.h"

Piece::Piece(int8_t color) : color_(color) {
}

int8_t Piece::GetColor() const {
    return color_;
}

void Piece::SetFirstMove(int32_t moveNum) {
    firstMove_ = moveNum;
}

int32_t Piece::GetFirstMove() const {
    return firstMove_;
}

MoveDirs King::Dirs() const {
    return MoveDirs{{Coordinate(0, 1), Coordinate(1, 1), Coordinate(1, 0), Coordinate(1, -1),
                     Coordinate(0, -1), Coordinate(-1, -1), Coordinate(-1, 0), Coordinate(-1, 1)},
                    1};
}

King::King(int8_t color) : Piece(color) {
}

std::string King::GetName() const {
    return "king" + std::to_string(GetColor());
}

MoveDirs Queen::Dirs() const {
    return MoveDirs{{Coordinate(0, 1), Coordinate(1, 1), Coordinate(1, 0), Coordinate(1, -1),
                     Coordinate(0, -1), Coordinate(-1, -1), Coordinate(-1, 0), Coordinate(-1, 1)},
                    7};
}

Queen::Queen(int8_t color) : Piece(color) {
}

std::string Queen::GetName() const {
    return "queen" + std::to_string(GetColor());
}

MoveDirs Rook::Dirs() const {
    return MoveDirs{{Coordinate(0, 1), Coordinate(1, 0), Coordinate(0, -1), Coordinate(-1, 0)}, 7};
}

Rook::Rook(int8_t color) : Piece(color) {
}

std::string Rook::GetName() const {
    return "rook" + std::to_string(GetColor());
}

MoveDirs Bishop::Dirs() const {
    return MoveDirs{{Coordinate(1, 1), Coordinate(1, -1), Coordinate(-1, -1), Coordinate(-1, 1)},
                    7};
}

Bishop::Bishop(int8_t color) : Piece(color) {
}

std::string Bishop::GetName() const {
    return "bishop" + std::to_string(GetColor());
}

MoveDirs Knight::Dirs() const {
    return MoveDirs{{Coordinate(1, 2), Coordinate(2, 1), Coordinate(2, -1), Coordinate(1, -2),
                     Coordinate(-1, -2), Coordinate(-2, -1), Coordinate(-2, 1), Coordinate(-1, 2)},
                    1};
}

Knight::Knight(int8_t color) : Piece(color) {
}

std::string Knight::GetName() const {
    return "knight" + std::to_string(GetColor());
}

MoveDirs Pawn::Dirs() const {
    auto moveDirs = MoveDirs{{Coordinate(-1, 1 - 2 * color_), Coordinate(1, 1 - 2 * color_),
                              Coordinate(0, 1 - 2 * color_), Coordinate(0, 2 - 4 * color_)},
                             1};

    return moveDirs;
}

Pawn::Pawn(int8_t color) : Piece(color) {
}

std::string Pawn::GetName() const {
    return "pawn" + std::to_string(GetColor());
}
