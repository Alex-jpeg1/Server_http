#define CROW_USE_BOOST
#include "crow.h"
#include <filesystem>
#include <iostream>
#include <string>
namespace fs = std::filesystem;

struct LoggerMiddleware{

struct context{};

void before_handler(crow::request& req, crow::response& context&)
{
	std::cout<<req.url;
}

}

class Server{
 public:
	Server(int RunningPort = 18080, std::string addr = "127.0.0.1"):
	Port(RunningPort), 
	ip(addr)
	{}

	void run ()
	{
		app.bindaddr(ip).port(Port).multithreaded().run();			
	}
	
 private:
	int Port;
	std::string ip;
 	crow::App<LoggerMiddleware> app;
} 

int main()
{   
	Server server;
	
	server.run();	
}
