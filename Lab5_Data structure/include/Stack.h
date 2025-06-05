#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;
    int head;
    int arr[MAX_SIZE];
public:
    Stack();                            // Constructor: initialize head to -1 for empty stack
    bool push(int x);                   // Pushes x onto the stack, returns false if full
    int pop();                          // Removes and returns top element, returns -1 if empty
    int peek();                         // Returns top element without removing, -1 if empty
    bool isEmpty();                     // Checks whether the stack is empty
    bool isFull();                      // Checks whether the stack is full
    bool isPrim(int x);                 // Determines if x is a prime number
    int Gen_Random_Number();            // Generates and returns a pseudorandom number
    Stack Sort_Prim_Numbers(Stack &input); // Sorts prime numbers from input into new stack
};

#endif // STACK_H
