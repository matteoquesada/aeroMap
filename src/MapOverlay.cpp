#include "../include/MapOverlay.h"
#include <iostream>

// CONSTRUCTOR
MapOverlay::MapOverlay() {
	selected_route = -1;
	delete_mode = false;
}

// ADDS A NODE TO AN EXISTENT ROUTE
void MapOverlay::add_node(int x, int y) {
	Node * node = new Node(x, y);
	routes[selected_route].add_node(node);
}
 
// CREATES A NEW EMPTY ROUTE
void MapOverlay::create_route() {
	routes.push_back(Route());
	selected_route = routes.size() - 1;
}

// DELETES A ROUTE
void MapOverlay::delete_route() {
	routes.erase(routes.begin() + selected_route);
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
	selected_route = route_id;
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

// SAVES ALL ROUTES TO A FILE
void MapOverlay::save_routes() {
	ofstream file;
	file.open("userdata/routes.txt");

	for (int i = 0; i < routes.size(); i++) {
		Node* current = routes[i].get_start_node();

		while (current != nullptr) {
			file << current->get_x() << " " << current->get_y() << endl;
			current = current->get_next();
		}

		file << endl;
	}

	file.close();
}

// LOADS ALL ROUTES FROM A FILE
void MapOverlay::load_routes() {
	ifstream file;
	file.open("userdata/routes.txt");

	if (file.is_open()) {
		string line;

		while (getline(file, line)) {
			if (line == "") {
				create_route();
			}
			else {
				int x = stoi(line.substr(0, line.find(" ")));
				int y = stoi(line.substr(line.find(" ") + 1, line.length()));

				add_node(x, y);
			}
		}
	}

	file.close();
}


