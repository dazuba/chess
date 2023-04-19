#include "handler.h"

#include <iostream>

void Handler::GetValidMoves(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback, int x, int y) const {
    try {
        auto moves = board_.ValidMoves(Coordinate(x, y));
        Json::Value movesJson;
        for (const auto& move : moves) {
            Json::Value cord;
            cord["x"] = move.GetX();
            cord["y"] = move.GetY();
            movesJson.append(cord);
        }
        auto resp = drogon::HttpResponse::newHttpJsonResponse(movesJson);
        callback(resp);
    } catch (...) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        callback(resp);
    }
}

void Handler::GetBoard(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback) const {
    Json::Value boardJson;
    Json::Value piecesJson;
    boardJson["move_num"] = board_.GetMoveNum();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board_[Coordinate(i, j)] != nullptr) {
                Json::Value pieceJson; 
                pieceJson["name"] = board_[Coordinate(i, j)]->GetName();
                pieceJson["x"] = i;
                pieceJson["y"] = j;
                piecesJson.append(pieceJson);
            }
        }
    }

    boardJson["pieces"] = piecesJson;
    auto resp = drogon::HttpResponse::newHttpJsonResponse(boardJson);
    callback(resp);
}

void Handler::MakeMove(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback, int fromX, int fromY, int toX, int toY) {
    std::cout << "asd" << std::endl;
    auto resp = drogon::HttpResponse::newHttpResponse();
    try {
        board_.MakeMove(Move{Coordinate(fromX, fromY), Coordinate(toX, toY)});
        resp->setStatusCode(drogon::HttpStatusCode::k200OK);
    } catch (...) {
        resp->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
    }
    callback(resp);
}
