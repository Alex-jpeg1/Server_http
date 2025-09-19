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
    	auto page = crow::mustache::load("index.html");    	
    	return page.render();
    });

    CROW_ROUTE(app, "/static/<string>")
    .methods(crow::HTTPMethod::GET)([](std::string filename)
    {
    	std :: string completePath = "/src/" + filename;
    	auto response = crow::mustache::load(completePath);
    	return response.render();
    });    
    app.bindaddr("127.0.0.1").port(18080).multithreaded().run();
}
