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

QPointF Scene::GetCoords(size_t i, size_t j, bool color, size_t offset_x, size_t offset_y) const {
    if (color == 0) {
        size_t jj = Board::BOARD_SIZE - j - 1;
        return QPointF(offset_x + 80 * i, offset_y + 80 * jj);
    }

    size_t ii = Board::BOARD_SIZE - i - 1;
    return QPointF(offset_x + 80 * ii, offset_y + 80 * j);
}

void Scene::DrawBoard() {
    ClearItems();
    for (size_t i = 0; i < Board::BOARD_SIZE; ++i) {
        for (size_t j = 0; j < Board::BOARD_SIZE; ++j) {
            auto p = board_[Coordinate(i, j)];
            if (p != nullptr) {
                PieceItem* item =
                    new PieceItem(QString::fromStdString("../media/" + p->GetName() + ".svg"), i, j,
                                  p->GetColor() == board_.GetStepColor());
                QObject::connect(item, SIGNAL(Clicked(size_t, size_t)), this,
                                 SLOT(ShowAvailableMoves(size_t, size_t)));

                item->setPos(GetCoords(i, j, board_.GetStepColor()));
                addItem(item);
                items_.push_back(item);
            }
        }
    }

    qDebug() << board_.IsCheck(board_.GetStepColor());
    qDebug() << board_.IsStalemate(board_.GetStepColor());
    qDebug() << board_.IsCheckmate(board_.GetStepColor());
}

void Scene::ShowAvailableMoves(size_t i, size_t j) {
    ClearMoves();
    std::vector<Coordinate> moves = board_.ValidMoves(Coordinate(i, j));
    for (const Coordinate& crd : moves) {
        ValidMoveItem* move = new ValidMoveItem(i, j, crd.GetX(), crd.GetY());
        QObject::connect(move, SIGNAL(Clicked(size_t, size_t, size_t, size_t)), this,
                         SLOT(TryMakeMove(size_t, size_t, size_t, size_t)));

        move->setPos(GetCoords(crd.GetX(), crd.GetY(), board_.GetStepColor(), 20, 40));
        addItem(move);
        moves_.push_back(move);
    }
}

void Scene::TryMakeMove(size_t fromX_, size_t fromY_, size_t toX_, size_t toY_) {
    ClearMoves();

    board_.MakeMove(Move{Coordinate(fromX_, fromY_), Coordinate(toX_, toY_)});
    DrawBoard();
}

void Scene::ClearItems() {
    for (auto item : items_) {
        delete item;
    }
    items_.clear();
}

void Scene::ClearMoves() {
    for (auto move : moves_) {
        delete move;
    }
    moves_.clear();
}
