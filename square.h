#include "pieces.h"
using namespace std;

class Square {
private:
    Piece* piece;
    int attackCnt;

public:
    bool IsAttacked();

    bool GetColor();
};