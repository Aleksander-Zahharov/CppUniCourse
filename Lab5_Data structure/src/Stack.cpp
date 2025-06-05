#include "Stack.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

// Constructor: initializes the stack with head index -1 indicating empty
Stack::Stack() : head(-1) {}

// Pushes an integer x onto the stack if not full, prints confirmation
bool Stack::push(int x) {
    // Check for overflow
    if (isFull()) return false;
    // Place x at next head position
    arr[++head] = x;
    std::cout << x << " pushed" << std::endl;
    return true;
}

// Pops and returns the top element of the stack; returns -1 if empty
int Stack::pop() {
    if (isEmpty()) return -1;  // Underflow check
    return arr[head--];        // Return top then decrement head
}

// Returns the top element without removing it; -1 if stack is empty
int Stack::peek() {
    if (isEmpty()) return -1;
    return arr[head];
}

// Checks whether the stack is empty (no elements pushed)
bool Stack::isEmpty() {
    return head == -1;
}

// Checks whether the stack is full (reached MAX_SIZE)
bool Stack::isFull() {
    return head == MAX_SIZE - 1;
}

// Determines if x is a prime number using trial division
bool Stack::isPrim(int x) {
    if (x < 2) return false;  // Numbers less than 2 are not prime
    int limit = static_cast<int>(std::sqrt(x));
    for (int i = 2; i <= limit; ++i) {
        if (x % i == 0) return false;  // Found a divisor, not prime
    }
    return true;  // No divisors found, x is prime
}

// Generates and returns a pseudorandom number in range [0,999]
int Stack::Gen_Random_Number() {
    return rand() % 1000;
}

// Sorts the elements of 'input' stack into a new stack using insertion
// sort logic: repeatedly pop from input and insert into temp in sorted order
Stack Stack::Sort_Prim_Numbers(Stack &input) {
    Stack temp;  // Temporary stack to hold sorted values
    while (!input.isEmpty()) {
        int tmp = input.pop();
        // Move larger elements back to input to find correct place for tmp
        while (!temp.isEmpty() && temp.peek() > tmp) {
            input.push(temp.pop());
        }
        // Place tmp in its sorted position
        temp.push(tmp);
    }
    return temp;  // Return sorted stack
}
