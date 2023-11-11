#include "../include/Node.h"

Node::Node(int x, int y) : x(x), y(y), next(nullptr), prev(nullptr) {}

int Node::getX(){
    return x;
}

int Node::getY(){
    return y;
}

Node* Node::getNext(){
    return next;
}

Node* Node::getPrev(){
    return prev;
}

void Node::setNext(Node* nextNode) {
    next = nextNode;
}

void Node::setPrev(Node* prevNode) {
    prev = prevNode;
}