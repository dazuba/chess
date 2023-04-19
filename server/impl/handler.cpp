#include "handler.h"

void Handler::GetValidMoves(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback, int x, int y) {
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
    } catch (const std::runtime_error& ex) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        callback(resp);
    }
}

void Handler::GetBoard(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr&)> &&callback) {
    try {
        Json::Value boardJson;
        Json::Value peacesJson;
        boardJson["move_num"] = board_.GetMoveNum();

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board_[Coordinate(i, j)] != nullptr) {
                    Json::Value peaceJson; 
                    peaceJson["name"] = board_[Coordinate(i, j)]->GetName();
                    peaceJson["x"] = i;
                    peaceJson["y"] = j;
                    peacesJson.append(peaceJson);
                }
            }
        }

        boardJson["peaces"] = peacesJson;
        auto resp = drogon::HttpResponse::newHttpJsonResponse(boardJson);
        callback(resp);
    } catch (const std::runtime_error& ex) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        callback(resp);
    }
}
