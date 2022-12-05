#include "boarditem.h"

BoardItem::BoardItem(const QString& fileName, QSvgRenderer* renderer) : QGraphicsSvgItem(fileName) {
    setSharedRenderer(renderer);
}

BoardItem::~BoardItem() {}
