#include "../include/Route.h"

Route::Route() : head(nullptr), tail(nullptr) {}

// TODO: implement a way to fill and create the new node and its data
void Route::addNode(Node* node) { // the received node still needs to have its data created somewhere
	if (head == nullptr) {
		head = node;
		tail = node;
	} 
	else {
		tail->setNext(node);
		node->setPrev(tail);
	}
}

void Route::removeNode(Node* node) { // the recieved node alrady has its data created somewhere
	if (head == node) {
		head = node->getNext();
	}
	else if(tail == node){
		tail->getPrev()->setNext(nullptr);
		tail = tail->getPrev();
	}
	else {
		node->getPrev()->setNext(node->getNext());
		node->getNext()->setPrev(node->getPrev());
	}
	delete node;
}
