#pragma once

#include "Routes.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class MapOverlay {

	std::vector<Route> routes;
	

public:

	int selected_route;

	bool delete_mode;

	MapOverlay();

	// ADDS A NODE TO AN EXISTENT ROUTE
	void add_node(int x, int y);

	// CREATES A NEW EMPTY ROUTE
	void create_route();

	// CHANGE SELECTED ROUTE
	void change_selected_route(int route_id);

	// DRAW ALL ROUTES
	void draw(RenderWindow& window);

	// CHANGE DELETE MODE
	void change_delete_mode();

	// DELETE NODE
	void delete_node(int x, int y);




	





	
};