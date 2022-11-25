#pragma once
#include "coordinate.h"
#include <vector>

struct MoveDirs
{
    std::vector<Coordinate> dirs;
    int steps;
};
