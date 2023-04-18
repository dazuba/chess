#include "validmoveitem.h"

ValidMoveItem::ValidMoveItem(size_t fromX, size_t fromY, size_t toX, size_t toY)
    : QGraphicsEllipseItem(), fromX_(fromX), fromY_(fromY), toX_(toX), toY_(toY) {
    setRect(0, 0, 80, 80);
}

ValidMoveItem::~ValidMoveItem() {
}

void ValidMoveItem::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        emit Clicked(fromX_, fromY_, toX_, toY_);
        event->accept();
    }
    event->ignore();
}
