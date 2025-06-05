#include "Node.h"

// Default constructor, initializes the node with a value of 0 and the pointer to the next element as nullptr
Node::Node() {
	this->data = 0;
	this->next = nullptr;
}
// Another way to write this constructor
// Node::Node() : data(0), next(nullptr) {}

// Constructor with a parameter, initializes the node with the given value and the pointer to the next element as nullptr
Node::Node(int data) {
	this->data = data;
	this->next = nullptr;
}
// Another way to write this constructor
// Node::Node(int data) : data(data), next(nullptr) {}
