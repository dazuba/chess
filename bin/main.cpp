#include <drogon/drogon.h>

int main(int argc, char* argv[]) {
    drogon::app().setLogPath("./logs/")
                 .setLogLevel(trantor::Logger::kWarn)
                 .addListener("0.0.0.0", 7777)
                 .setThreadNum(16)
                 .enableRunAsDaemon()
                 .run();
}
