#include "boarditem.h"

BoardItem::BoardItem() : QGraphicsSvgItem("../media/board.svg") {
    setScale(80);
}

BoardItem::~BoardItem() {}

// QRectF BoardItem::boundingRect() const {
//     return QRectF(0, 0, 1, 1);
// }
