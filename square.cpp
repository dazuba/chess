#include "square.h"

bool Square::GetPieceColor() {
    if (piece == nullptr) {
        return 0;
    }
    return piece->GetColor();
}