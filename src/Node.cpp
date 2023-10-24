#include "../include/Node.h"

Node::Node(): x(0), y(0), next(nullptr), prev(nullptr) {}

Node::Node(int x, int y): x(x), y(y), next(nullptr), prev(nullptr) {}

void Node::setNext(Node* next) { this->next = next; }

void Node::setPrev(Node* prev) { this->prev = prev; }

Node* Node::getNext() { return next; }

Node* Node::getPrev() { return prev; }

int Node::getX() { return x; }

int Node::getY() { return y; }