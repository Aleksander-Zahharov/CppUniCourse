#include "Queue.h"
#include <iostream>

// Constructor: initialize empty queue with front and rear = -1
template<typename T>
Queue<T>::Queue() : front(-1), rear(-1), count(0) {}

// Check if the queue is full
template<typename T>
bool Queue<T>::isFull() const {
    return count == MAX_SIZE;
}

// Check if the queue is empty
template<typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

// Add element x to the rear of the queue
template<typename T>
void Queue<T>::EnQueue(T x) {
    if (isFull()) {
        std::cout << "Queue is full!!" << std::endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    arr[rear] = x;
    count++;
    std::cout << x;
    if (count <= MAX_SIZE) std::cout << " ";
}

// Remove and return element from the front of the queue
template<typename T>
T Queue<T>::DeQueue() {
    if (isEmpty()) {
        std::cout << "Queue is empty!!" << std::endl;
        return T();
    }
    T val = arr[front];
    std::cout << "Deleted => " << val << std::endl;
    if (count == 1) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    count--;
    return val;
}

// Print all elements from front to rear
template<typename T>
void Queue<T>::PrintQueue() const {
    if (isEmpty()) return;
    std::cout << "Queue elements : ";
    for (int i = 0; i < count; ++i) {
        int idx = (front + i) % MAX_SIZE;
        std::cout << arr[idx];
        if (i < count - 1) std::cout << "\t";
    }
    std::cout << std::endl;
}

// Search for x in the queue and print result
template<typename T>
void Queue<T>::Search(T x) const {
    int loc = -1;
    for (int i = 0; i < count; ++i) {
        int idx = (front + i) % MAX_SIZE;
        if (arr[idx] == x) {
            loc = i;
            break;
        }
    }
    if (loc == -1) {
        std::cout << x << " is not present at the Queue" << std::endl;
    } else {
        std::cout << x << " is present at the Queue in location: " << loc << std::endl;
    }
}

// Explicit instantiation for int type
template class Queue<int>;
