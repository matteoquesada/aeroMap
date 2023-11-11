#include "../include/MapOverlay.h"


MapOverlay::MapOverlay() {
	selected_route = -1;
	delete_mode = false;
}

void MapOverlay::add_node(int x, int y) {
	Node * node = new Node(x, y);
	routes[selected_route].addNode(node);
}
 
void MapOverlay::create_route() {
	routes.push_back(Route());
	selected_route = routes.size() - 1;
}

void MapOverlay::draw(RenderWindow& window) {
	for (int i = 0; i < routes.size(); i++) {
		routes[i].draw(window);
	}
}

void MapOverlay::change_selected_route(int route_id) {
	selected_route = route_id;
}

void MapOverlay::change_delete_mode() {
	delete_mode = !delete_mode;
}

void MapOverlay::delete_node(int x, int y) {
	Node* current = routes[selected_route].getStartNode();
	while (current != nullptr) {
		if (current->getX() == x && current->getY() == y) {
			if (current->getPrev() != nullptr) {
				current->getPrev()->setNext(current->getNext());
			}
			if (current->getNext() != nullptr) {
				current->getNext()->setPrev(current->getPrev());
			}
			delete current;
			break;
		}
		current = current->getNext();
	}
}

