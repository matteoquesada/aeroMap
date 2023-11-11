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
