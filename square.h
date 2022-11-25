#include "pieces.h"
using namespace std;

class Square {
private:
    Piece* piece;
    int attackCnt;
    

public:
    int isEnPassant = 0;

    bool IsAttacked();

    bool GetPieceColor();
};