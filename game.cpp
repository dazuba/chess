#include "game.h"

void Game::MakeMove(Coordinate crd1, Coordinate crd2) {
    if(!board.MakeMove(crd1, crd2)) {
        return;
    }
    moves.push_back(Move(crd1, crd2, board.GetPiece(crd2)));
}