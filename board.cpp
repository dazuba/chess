#include "board.h"

int Board::GetColor(Coordinate crd) {
    return d[crd.y][crd.x].GetColor();
}