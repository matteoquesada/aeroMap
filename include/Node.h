#pragma once

class Node {

private:

    int x; int y;
    
    Node* next;
    Node* prev;

public:

    Node(int x, int y);
    int get_x(); int get_y();
    
    Node* get_next();
    Node* get_prev();

    void set_next(Node* next_node);
    void set_prev(Node* prev_node);
};