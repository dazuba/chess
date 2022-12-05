#include "scene.h"

Scene::Scene() : QGraphicsScene() {
    setSceneRect(0, 0, 800, 800);

    boarditem_ = new BoardItem();
    boarditem_->setPos(20, 40);
    addItem(boarditem_);

    DrawBoard();
}

Scene::~Scene() {
    delete boarditem_;
}

void Scene::DrawBoard() {
    for (auto item : items_) {
        delete item;
    }
    items_.clear();
    for (size_t i = 0; i < Board::BOARD_SIZE; ++i) {
        for (size_t j = 0; j < Board::BOARD_SIZE; ++j) {
            size_t jj = Board::BOARD_SIZE - j - 1;
            auto p = board_[Coordinate(i, j)];
            if (p != nullptr) {
                PieceItem* item = new PieceItem(QString::fromStdString("../media/" + p->GetName() + ".svg"));
                item->setPos(15 + 80 * i, 35 + 80 * jj);
                addItem(item);
                items_.push_back(item);
            }
        }
    }
}
