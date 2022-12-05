#pragma once

#include <QGraphicsScene>
#include <QSvgRenderer>

#include "boarditem.h"

class Scene : public QGraphicsScene {
    Q_OBJECT

public:
    Scene();
    ~Scene();

private:
    BoardItem* board_;
    QSvgRenderer* renderer_;
};
