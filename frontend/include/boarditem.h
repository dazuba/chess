#pragma once

#include <QGraphicsSvgItem>

class BoardItem : public QGraphicsSvgItem {
public:
    BoardItem();
    ~BoardItem();

private:
    // QRectF boundingRect() const override;
};
