#include "../include/MapOverlay.h"
#include <iostream>

// CONSTRUCTOR
MapOverlay::MapOverlay() {
	selected_route = -1;
	delete_mode = false;
}

// ADDS A NODE TO AN EXISTENT ROUTE
void MapOverlay::add_node(int x, int y) {
	Node* node = new Node(x, y);
	routes[selected_route].add_node(node);
}

// CREATES A NEW EMPTY ROUTE
void MapOverlay::create_route() {
	routes.push_back(Route());
	selected_route = routes.size() - 1;
}

// DELETES A ROUTE
void MapOverlay::delete_route() {
	routes.erase(selected_route);
	selected_route = -1;
}

// DRAW ALL ROUTES
void MapOverlay::draw(RenderWindow& window) {
	for (int i = 0; i < routes.size(); i++) {
		routes[i].draw(window);
	}
}

// CHANGE ROUTE COLOR
void MapOverlay::change_route_color(Color color) {
	routes[selected_route].change_color(color);
}

// CHANGE SELECTED ROUTE
void MapOverlay::change_selected_route(int route_id) {
	if (selected_route + 1 < routes.size()) {
		selected_route++;
	}
	else {
		selected_route = 0;
	}

}

// CHANGE DELETE MODE
void MapOverlay::change_delete_mode() {
	delete_mode = !delete_mode;
}

// DELETES A NODE IF THE CLICK IS IN A RANGE OF 5 PIXELS
void MapOverlay::delete_node(int x, int y) {
	Node* current = routes[selected_route].get_start_node();

	while (current != nullptr) {

		if (current->get_x() >= x - 10 && current->get_x() <= x + 10 && current->get_y() >= y - 10 && current->get_y() <= y + 10) {
			routes[selected_route].delete_node(current);

			delete current;

			break;
		}

		current = current->get_next();
	}

}

// SAVES ALL ROUTES, CORRESPONDING NODES AND COLORS TO A FILE
// FORMAT:
// Color: 4294967295 // COLOR IS IN INTEGER FORMAT (RGBA) (255, 255, 255, 255) -> 4294967295 (WHITE)
// Node: 100 100
// Node: 200 200
// Node: 300 300
// // NEW LINE
// ...
void MapOverlay::save_routes() {
	ofstream file("userdata/routes.txt");
	if (!file.is_open()) {
		cerr << "Error opening file for writing." << endl;
		return;
	}

	for (int i = 0; i < routes.size(); ++i) {
		file << "Color: " << routes[i].get_color().toInteger() << endl;

		Node* current = routes[i].get_start_node();
		while (current != nullptr) {
			file << "Node: " << current->get_x() << " " << current->get_y() << endl;
			current = current->get_next();
		}

		file << endl; 
	}

	file.close();
}

// LOADS ALL ROUTES, CORRESPONDING NODES AND COLORS FROM A FILE
// LOADS ALL ROUTES FROM A FILE AND CREATES THE CORRESPONDING NODES
// HAS NO ERROR HANDLING WHEN USED IF THERE ARE EXISTENT ROUTES DRAWN ON THE MAP
void MapOverlay::load_routes() {

	ifstream file("userdata/routes.txt");
	if (!file.is_open()) {
		cerr << "MEGA-ERROR: EL ARCHIVO ESPECIFICADO EXPLOTO O MERAMENTE NO EXISTE" << endl;
		return;
	}

	string line;
	Route currentRoute;
	Color currentColor;

	while (getline(file, line)) {
		if (line.find("Color:") != string::npos) {
			currentColor = Color(stoul(line.substr(line.find(" ") + 1)));
		}
		else if (line.find("Node:") != string::npos) {
			size_t spacePos = line.find(" ");
			int x = stoi(line.substr(spacePos + 1, line.find(" ", spacePos + 1)));
			int y = stoi(line.substr(line.find(" ", spacePos + 1) + 1));
			currentRoute.add_node(new Node(x, y));
		}
		else if (line.empty()) {

			currentRoute.change_color(currentColor);
			routes.push_back(currentRoute);

			currentRoute = Route(); // RESETS THE ROUTE
		}
	}

	currentRoute.change_color(currentColor);
	routes.push_back(currentRoute);

}



// SHOW/HIDE ROUTE ON THE MAP
void MapOverlay::show_hide_route() {
	routes[selected_route].show_hide();
}

// DESTRUCTOR
MapOverlay::~MapOverlay() {
	for (int i = 0; i < routes.size(); i++) {
		Node* current = routes[i].get_start_node();

		while (current != nullptr) {
			Node* temp = current;
			current = current->get_next();
			delete temp;
		}
	}
}


