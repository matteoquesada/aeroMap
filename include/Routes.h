#pragma once
#include <vector>
#include "Route.h"

class Routes {

	std::vector<Route> routes;
	int selected_route;

public:

	Routes();

	void add_route();

};