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
            auto p = board_.GetPiece(Coordinate(i, j));
            if (p != nullptr) {
                PieceItem* item = new PieceItem("../media/black_king.svg");
                item->setPos(15 + 80 * i, 35 + 80 * j);
                addItem(item);
                items_.push_back(item);
            }
        }
    }
}
