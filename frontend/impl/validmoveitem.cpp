#include "validmoveitem.h"

ValidMoveItem::ValidMoveItem(size_t x, size_t y) : QGraphicsEllipseItem(), x_(x), y_(y) {
    setRect(0, 0, 80, 80);
}

ValidMoveItem::~ValidMoveItem() {}

void ValidMoveItem::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        emit Clicked(x_, y_);
        event->accept();
    }
    event->ignore();
}
