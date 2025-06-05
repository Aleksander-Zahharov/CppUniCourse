#ifndef NODE_H
#define NODE_H

#include<iostream>

class Node {
public:
    int data;      // stores the integer value of the node
    Node* next;    // pointer to the next node in the list

    Node();        // default ctor: initializes data to 0 and next to nullptr
    Node(int data); // parameterized ctor: sets node data and next to nullptr
};
#endif
