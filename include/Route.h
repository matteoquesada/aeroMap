#pragma once

#include "Node.h"

#include "Node.h"

class Route {
private:
    Node* head;
    Node* tail;

public:
    Route();
    Route(Node* head, Node* tail);
    void setStartNode(Node* head);
    Node* getStartNode();
    void setEndNode(Node* tail);
    Node* getEndNode();
};