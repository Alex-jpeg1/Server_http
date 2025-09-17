#define CROW_USE_BOOST
#include "crow.h"
#include <filesystem>
#include <iostream>
#include <string>
namespace fs = std::filesystem;

int main()
{
    crow::SimpleApp app;
    
    auto currDir = fs::current_path();
    crow::mustache::set_base(currDir.string());

    CROW_ROUTE(app, "/<string>")([](std::string nume) {
        auto page  = crow::mustache::load("mainpage.html");
        crow::mustache::context ctx({{"name",nume}});
        return page.render(ctx);
    });

    app.bindaddr("127.0.0.1").port(18080).multithreaded().run();
}
