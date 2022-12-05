#pragma once

#include <QGraphicsSvgItem>

class PieceItem : public QGraphicsSvgItem {
public:
    PieceItem(const QString& fileName);
    ~PieceItem();

private:
    // QRectF boundingRect() const override;
};
