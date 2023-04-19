#pragma once

#include <functional>

#include <drogon/HttpController.h>

#include "board.h"

class Handler : public drogon::HttpController<Handler> {
public:
    METHOD_LIST_BEGIN

    METHOD_ADD(Handler::GetValidMoves, "/valid-moves?x={1}&y={2}", drogon::Get);
    METHOD_ADD(Handler::GetBoard, "/get-board", drogon::Get);
    METHOD_ADD(Handler::MakeMove, "/make-move?fromX={1}&fromY={2}&toX={3}&toY={4}", drogon::Post);

    METHOD_LIST_END

    void GetValidMoves(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback, int x, int y) const;
    void GetBoard(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback) const;
    void MakeMove(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback, int fromX, int fromY, int toX, int toY);

private:
    Board board_;
};
