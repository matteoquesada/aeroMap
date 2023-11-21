#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Node.h"

class Route {

private:

    Node* head;
    Node* tail;
    Color color;

    bool is_drawable;

public:

    // CONSTRUCTORS
    Route();
    Route(Node* head, Node* tail);

    // GETTERS AND SETTERS
    void set_start_node(Node* head);
    Node* get_start_node();
    void set_end_node(Node* tail);
    Node* get_end_node();
    Color get_color();

    // ADDS A NODE TO THE END OF THE ROUTE
    void add_node(Node* node);

    // DELETES A NODE FROM THE ROUTE
    void draw(RenderWindow& window);

    // DRAWS THE ENTIRE ROUTE WITH NODES AND LINES WITHIN THE WINDOW
    void delete_node(Node* node);

    // CHANGE ROUTE COLOR
    void change_color(Color color);

    // SHOW/HIDE ROUTE ON THE MAP
    void show_hide();

    // DESTRUCTOR
    ~Route();
};