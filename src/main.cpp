#define CROW_USE_BOOST
#include "crow.h"
#include <filesystem>
#include <iostream>
#include <string>
namespace fs = std::filesystem;

struct LoggerMiddleware{

struct context{};

void before_handle(crow::request& req, crow::response& res, context& ctx)
{
	std::cout<<req.url;
}

void after_handle(crow::request& req, crow::response& res, context& ctx)
{
	
}

};

class Server{
 public:
	Server(int RunningPort = 18080, std::string addr = "127.0.0.1"):Port(RunningPort), ip(addr){}

	void setupRoutes()
	{
		auto currDir = fs::current_path();
		crow::mustache::set_base(currDir.string());
		
		app.route_dynamic("/").methods(crow::HTTPMethod::GET)([]()
		{
			auto page =crow::mustache::load("index.html");
			return page.render(); 
		});

		app.route_dynamic("/static/<string>").methods(crow::HTTPMethod::GET)([&currDir](std::string filename)
		{
			std :: string completePath = currDir.string() + "/templates/" + filename;
			auto response = crow::mustache::load(completePath);
			return response.render();
		});

		app.route_dynamic("/login").methods(crow::HTTPMethod::POST)([](const crow::request& req)
		{
			auto body = crow::query_string(req.body);

			std::string user = body.get("user") ? body.get("user") : "";
			std::string pass = body.get("pass") ? body.get("pass") : "";

			// Check if the user is trying to indentify correctly

			
			if(user.size() ==  0)
			{
				return crow::response(401, "Username must be an array");
			}
			
			if(pass.size() == 0)
			{
				return crow::response(401, "Password cannot be empty");
			}
			
			return crow::response(200, "Action succesful");			
		});
	}
	
	void Run()
	{
		setupRoutes();
		app.bindaddr(ip).port(Port).multithreaded().run();			
	}

	
 private:
	int Port;
	std::string ip;
 	crow::App<LoggerMiddleware> app;
}; 

int main()
{   
	Server server;
	
	server.Run();	
}
