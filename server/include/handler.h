#pragma once

#include <functional>

#include <drogon/HttpController.h>

#include "board.h"

class Handler : public drogon::HttpController<Handler> {
public:
    METHOD_LIST_BEGIN

    METHOD_ADD(Handler::GetValidMoves, "/valid-moves?x={1}&y={2}", drogon::Get);
    METHOD_ADD(Handler::GetBoard, "/get-board", drogon::Get);

    METHOD_LIST_END

    void GetValidMoves(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback, int x, int y);
    void GetBoard(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback);

private:
    Board board_;
};
