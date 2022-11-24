#include "square.h"

bool Square::GetColor() {
    if (piece == nullptr) {
        return 0;
    }
    return piece->GetColor();
}