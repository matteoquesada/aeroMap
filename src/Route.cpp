#include "../include/Route.h"


Route::Route() : head(nullptr), tail(nullptr) {
}

Route::Route(Node* head, Node* tail) : head(head), tail(tail) {
}

void Route::setStartNode(Node* head) {
    this->head = head;
}

Node* Route::getStartNode() {
    return head;
}

void Route::setEndNode(Node* tail) {
    this->tail = tail;
}

Node* Route::getEndNode() {
    return tail;
}

// ADDS A NODE TO THE END OF THE ROUTE
void Route::addNode(Node* node) {
    if (head == nullptr) {
		head = node;
		tail = node;
    }
    else {
		tail->setNext(node);
		node->setPrev(tail);
		tail = node;
	}
}

void Route::draw(RenderWindow& window) {
	Node* current = head;
	while (current != nullptr) {
		CircleShape circle(5);
		circle.setFillColor(Color::Red);
		circle.setPosition(current->getX(), current->getY());
		window.draw(circle);
		current = current->getNext();
	}
}
