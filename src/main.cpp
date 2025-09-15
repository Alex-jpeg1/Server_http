#define CROW_USE_BOOST
#include "crow.h"

int main()
{	 
	crow::SimpleApp app;

	CROW_ROUTE(app,"/")([]()
	{ 
	return "Hello world";
	});

	app.bindaddr("127.0.0.1").port(18080).multithreaded().run();
	 return 0;
}
