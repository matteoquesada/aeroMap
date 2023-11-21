#pragma once

class Node {

private:

    int x; int y;
    
    Node* next;
    Node* prev;

public:

    // CONSTRUCTORS
    Node();
    Node(int x, int y);

    // GETTERS
    int get_x(); 
    int get_y();
    
    // MORE GETTERS
    Node* get_next();
    Node* get_prev();

    // SETTERS
    void set_next(Node* next_node);
    void set_prev(Node* prev_node);
};