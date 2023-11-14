#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

#include <fstream>

#include "Route.h"

class MapOverlay {

private:

	std::vector<Route> routes;
	
public:

	int selected_route;

	bool delete_mode;

	// CONSTRUCTOR
	MapOverlay();

	// ADDS A NODE TO AN EXISTENT ROUTE
	void add_node(int x, int y);

	// CREATES A NEW EMPTY ROUTE
	void create_route();

	// DELETES A ROUTE
	void delete_route();

	// CHANGE SELECTED ROUTE
	void change_selected_route(int route_id);

	// DRAW ALL ROUTES
	void draw(RenderWindow& window);

	// CHANGE DELETE MODE
	void change_delete_mode();

	// DELETE NODE
	void delete_node(int x, int y);

	// CHANGE ROUTE COLOR
	void change_route_color(Color color);

	// SAVE ROUTES TO FILE
	void save_routes();

	// LOAD ROUTES FROM FILE
	void load_routes();




	





	
};