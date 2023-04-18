#pragma once

#include <QGraphicsScene>
#include <vector>

#include "board.h"
#include "boarditem.h"
#include "pieceitem.h"
#include "validmoveitem.h"

class Scene : public QGraphicsScene {
    Q_OBJECT

public:
    Scene();
    ~Scene();

public slots:
    void ShowAvailableMoves(size_t i, size_t j);
    void TryMakeMove(size_t fromX_, size_t fromY_, size_t toX_, size_t toY_);

private:
    QPointF GetCoords(size_t i, size_t j, bool color, size_t offset_x = 15,
                      size_t offset_y = 35) const;
    void DrawBoard();

    void ClearItems();
    void ClearMoves();

    Board board_;
    BoardItem* boarditem_;
    QSvgRenderer* renderer_;

    std::vector<PieceItem*> items_;
    std::vector<ValidMoveItem*> moves_;
};
