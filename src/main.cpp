#define CROW_USE_BOOST
#include "crow.h"

int main()
{	 
	crow::SimpleApp app;

	crow::mustache::set_base("../frontend");
	CROW_ROUTE(app,"/")([]()
	{ 
	auto page = crow::mustache::load_text("mainpage.html");
	
	return page;
	});

	app.bindaddr("127.0.0.1").port(18080).multithreaded().run();
	 return 0;
}
