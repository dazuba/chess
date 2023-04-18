#pragma once

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>

class ValidMoveItem : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT

public:
    ValidMoveItem(size_t fromX_, size_t fromY_, size_t toX_, size_t toY_);
    ~ValidMoveItem();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

signals:
    void Clicked(size_t fromX_, size_t fromY_, size_t toX_, size_t toY_);

private:
    size_t fromX_, fromY_;
    size_t toX_, toY_;
};
