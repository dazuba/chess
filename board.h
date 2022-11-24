#pragma once
#include <vector>
#include "square.h"

class Board {
private:
    static std::vector<std::vector<Square>> d;

public:
    int GetColor(Coordinate crd);
};