#pragma once

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSvgItem>

class PieceItem : public QGraphicsSvgItem {
    Q_OBJECT

public:
    PieceItem(const QString& fileName, size_t x, size_t y, bool can_move);
    ~PieceItem();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

signals:
    void Clicked(size_t x, size_t y);

private:
    size_t x_, y_;
    bool can_move_;
};
