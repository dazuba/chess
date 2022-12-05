#pragma once

#include <QGraphicsSvgItem>
#include <QSvgRenderer>

class BoardItem : public QGraphicsSvgItem {
public:
    BoardItem(const QString& fileName, QSvgRenderer* renderer);
    ~BoardItem();
};
