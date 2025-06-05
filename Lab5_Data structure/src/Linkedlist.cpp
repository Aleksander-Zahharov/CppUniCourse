#include "Linkedlist.h"
#include <iostream>
#include <stdexcept>

// Constructor: initialize empty list with head = nullptr
Linkedlist::Linkedlist() : head(nullptr) {}

// Destructor: delete all nodes to free memory
Linkedlist::~Linkedlist() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Add a new node with specified data to the end of the list
void Linkedlist::addNode(int data) {
    Node* newNode = new Node(data);
    if (!head) head = newNode;  // first node
    else {
        // traverse to the last node
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Print all node data separated by spaces
void Linkedlist::printList() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data;
        if (temp->next) std::cout << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Return the number of nodes in the list
int Linkedlist::lengthList() const {
    int length = 0;
    Node* temp = head;
    while (temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Delete node at the given index if within range
void Linkedlist::deleteNode_Index(int index) {
    if (!isRange(index)) return;
    Node* temp = head;
    if (index == 0) {
        head = head->next;
        delete temp;
        return;
    }
    // find node before the one to delete
    for (int i = 0; i < index - 1; ++i) temp = temp->next;
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

// Delete the first node containing the specified data
void Linkedlist::deleteNode_Data(int data) {
    Node* temp = head;
    Node* prev = nullptr;
    while (temp && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;  // data not found
    if (!prev) head = temp->next;  // delete head
    else prev->next = temp->next;
    delete temp;
}

// Check whether the list is empty
bool Linkedlist::isListEmpty() const {
    return head == nullptr;
}

// Validate index range and print error if out-of-bounds
bool Linkedlist::isRange(int index) const {
    if (index < 0 || index >= lengthList()) {
        std::cout << "Index out of range" << std::endl;
        return false;
    }
    return true;
}

// Search for data and print location or not found
void Linkedlist::searchNode(int data) const {
    Node* temp = head;
    int loc = 0;
    while (temp) {
        if (temp->data == data) {
            std::cout << data << " is present at the Linked List in location: " << loc;
            return;
        }
        temp = temp->next;
        loc++;
    }
    std::cout << data << " is not present at the Linked list" << std::endl;
}
