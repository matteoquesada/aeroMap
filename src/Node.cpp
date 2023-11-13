#include "../include/Node.h"

// CONSTRUCTOR
Node::Node(int x, int y) : x(x), y(y), next(nullptr), prev(nullptr) {}

// GETTERS AND SETTERS
int Node::get_x(){
    return x;
}

// GETTERS AND SETTERS
int Node::get_y(){
    return y;
}

// GETTERS AND SETTERS
Node* Node::get_next(){
    return next;
}

// GETTERS AND SETTERS
Node* Node::get_prev(){
    return prev;
}

// GETTERS AND SETTERS
void Node::set_next(Node* nextNode) {
    next = nextNode;
}

// GETTERS AND SETTERS
void Node::set_prev(Node* prevNode) {
    prev = prevNode;
}