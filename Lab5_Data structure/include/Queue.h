#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

static const int MAX_SIZE = 5;

/**
 * @brief Template-based circular FIFO queue with fixed capacity.
 *
 * A circular queue uses a fixed-size buffer and wraps front/rear pointers
 * using modulo arithmetic, allowing reuse of slots freed by dequeuing.
 * Unlike a linear queue that may require shifting elements after dequeue,
 * a circular queue maintains constant time operations and better memory usage.
 */
template<typename T>
class Queue {
private:
	T arr[MAX_SIZE];
	int front, rear;
	int count;
public:
	Queue();                   // Constructor: initializes front and rear to -1 (empty circular queue)
	bool isFull() const;       // Checks if the queue is full (count == MAX_SIZE)
	bool isEmpty() const;      // Checks if the queue is empty (count == 0)
	void EnQueue(T x);         // Adds element x; rear = (rear + 1) % MAX_SIZE
	T DeQueue();               // Removes front; front = (front + 1) % MAX_SIZE or reset if empty
	void PrintQueue() const;   // Prints elements from front to rear in circular order
	void Search(T x) const;    // Searches for x in the circular buffer
};

#endif // QUEUE_H
