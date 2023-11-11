#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
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
    void addNode(Node* node);
    void draw(RenderWindow& window);
};