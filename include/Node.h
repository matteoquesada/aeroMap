#pragma once

class Node {
private:
    int x;
    int y;
    Node* next;
    Node* prev;

public:
    Node(int x, int y);
    int getX();
    int getY();
    Node* getNext();
    Node* getPrev();
    void setNext(Node* nextNode);
    void setPrev(Node* prevNode);
};