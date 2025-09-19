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

    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)([]() {
    	auto page = crow::mustache::load("mainpage.html");
    	
    	return page.render();
    });

    app.bindaddr("127.0.0.1").port(18080).multithreaded().run();
}
