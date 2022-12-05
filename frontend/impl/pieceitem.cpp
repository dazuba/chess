#include "pieceitem.h"

PieceItem::PieceItem(const QString& fileName) : QGraphicsSvgItem(fileName) {
    setScale(2);
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
}

PieceItem::~PieceItem() {}
