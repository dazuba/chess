#include "board.h"

int main() {
    Board board;
    int moveNum = 1;
    int condition = 0;

    while (condition <= 1) {
        Coordinate crd1;

        if (board.GetColor(crd1) != (moveNum & 1)) {
            continue;
        }

        Coordinate crd2;

        if (board.GetColor(crd2) == (moveNum & 1)) {
            continue;
        }

        
    }
}