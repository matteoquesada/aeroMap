#include "../include/Route.h"

// CONSTRUCTORS
Route::Route() : head(nullptr), tail(nullptr), color(Color::White), is_drawable(true) {
}

Route::Route(Node* head, Node* tail) : head(head), tail(tail), color(Color::White), is_drawable(true) {
}

// GETTERS AND SETTERS
void Route::set_start_node(Node* head) {
	this->head = head;
}

Node* Route::get_start_node() {
	return head;
}

void Route::set_end_node(Node* tail) {
	this->tail = tail;
}

Node* Route::get_end_node() {
	return tail;
}

// ADDS A NODE TO THE END OF THE ROUTE
void Route::add_node(Node* node) {
	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else {
		tail->set_next(node);
		node->set_prev(tail);
		tail = node;
	}
}

// DELETES A NODE FROM THE ROUTE
void Route::delete_node(Node* node) {
	if (node == head) {
		head = node->get_next();
		head->set_prev(nullptr);
	}
	else if (node == tail) {
		tail = node->get_prev();
		tail->set_next(nullptr);
	}
	else {
		node->get_prev()->set_next(node->get_next());
		node->get_next()->set_prev(node->get_prev());
	}
}

// DRAWS THE ENTIRE ROUTE WITH NODES AND LINES WITHIN THE WINDOW
void Route::draw(RenderWindow& window) {

	if (!is_drawable) return;

	Node* current = head;
	while (current != nullptr) {

		// DRAWING THE NODE ITSELF WITH A BLACK BORDER
		CircleShape circle(5);
		circle.setFillColor(color);
		circle.setPosition(current->get_x() - 3, current->get_y() - 3);

		CircleShape border(6);
		border.setFillColor(Color::Black);
		border.setPosition(current->get_x() - 3, current->get_y() - 3);

		// DRAWING THE LINE BETWEEN NODES
		if (current->get_next() != nullptr) {
			Vertex line[] =
			{
				Vertex(Vector2f(current->get_x(), current->get_y())),
				Vertex(Vector2f(current->get_next()->get_x(), current->get_next()->get_y()))
			};
			window.draw(line, 2, Lines);
		}
		window.draw(border);
		window.draw(circle);
		current = current->get_next();
	}
}


// CHANGES THE COLOR OF THE ROUTE
void Route::change_color(Color color) {
	this->color = color;
}

// CHANGES THE VISIBILITY OF THE ROUTE
void Route::show_hide() {
	is_drawable = !is_drawable;
}

// DESTRUCTOR
Route::~Route() {
}

// GET COLOR 
Color Route::get_color() {
	return color;
}

