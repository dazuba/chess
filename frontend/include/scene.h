#pragma once

#include <QGraphicsScene>
#include <vector>

#include "board.h"
#include "boarditem.h"
#include "pieceitem.h"

class Scene : public QGraphicsScene {
    Q_OBJECT

public:
    Scene();
    ~Scene();

private:
    void DrawBoard();

    Board board_;
    BoardItem* boarditem_;
    QSvgRenderer* renderer_;

    std::vector<PieceItem*> items_;
};
