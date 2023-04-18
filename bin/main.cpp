#include <drogon/drogon.h>

int main(int argc, char* argv[]) {
    drogon::app().loadConfigFile("configs/drogon.json");
    drogon::app().run();
    return 0;
}
