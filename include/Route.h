#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Node.h"

class Route {

private:

    Node* head;
    Node* tail;
    Color color;

public:

    Route(); Route(Node* head, Node* tail);
   
    void set_start_node(Node* head); Node* get_start_node();
    
    void set_end_node(Node* tail); Node* get_end_node();
    
    void add_node(Node* node);

    void draw(RenderWindow& window);

    void delete_node(Node* node);

    void change_color(Color color);
};