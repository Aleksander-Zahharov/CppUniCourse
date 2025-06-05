#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

class Linkedlist {
private:
    Node* head;
public:
    Linkedlist();               // Initializes head to nullptr
    ~Linkedlist();              // Destroys all nodes and frees memory
    void addNode(int data);     // Adds a new node with given data at the end of the list
    void printList() const;     // Prints all node data separated by spaces
    int lengthList() const;     // Returns the number of nodes in the list
    void deleteNode_Index(int index); // Deletes the node at the specified index
    bool isListEmpty() const;   // Checks whether the list is empty
    void deleteNode_Data(int data);   // Deletes the first node containing the specified data
    bool isRange(int index) const;    // Checks if the given index is within valid range
    void searchNode(int data) const;  // Searches for data and prints its location or not found
};

#endif // LINKEDLIST_H
