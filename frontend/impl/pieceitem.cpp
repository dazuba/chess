#include "pieceitem.h"

PieceItem::PieceItem(const QString& fileName, size_t x, size_t y, bool can_move)
    : QGraphicsSvgItem(fileName), x_(x), y_(y), can_move_(can_move) {
    setScale(2);
}

PieceItem::~PieceItem() {
}

void PieceItem::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton && can_move_) {
        emit Clicked(x_, y_);
        event->accept();
    }
    event->ignore();
}
