#pragma once

#include <vector>

#include "coordinate.h"

struct MoveDirs {
    std::vector<Coordinate> dirs;
    uint8_t steps;
};
