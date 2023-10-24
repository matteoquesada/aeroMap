#pragma once

class Node {

	int x;
	int y;

	Node* next;
	Node* prev;

public:

	Node();

	Node(int x, int y);

	void setNext(Node* next);

	void setPrev(Node* prev);

	Node* getNext();

	Node* getPrev();

	int getX();

	int getY();

};
