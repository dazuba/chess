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
