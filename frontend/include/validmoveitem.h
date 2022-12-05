#pragma once

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>

class ValidMoveItem : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
    
public:
    ValidMoveItem(size_t x, size_t y);
    ~ValidMoveItem();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

signals:
    void Clicked(size_t x, size_t y);

private:
    size_t x_, y_;
};
