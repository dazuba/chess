#include "scene.h"

Scene::Scene() : QGraphicsScene() {
    setSceneRect(0, 0, 800, 800);

    renderer_ = new QSvgRenderer();
    board_ = new BoardItem("../media/board.svg", renderer_);
    addItem(board_);
}

Scene::~Scene() {
    delete board_;
    delete renderer_;
}
