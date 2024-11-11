#include "Queue.h"
#include <iostream>

void initQueue(Queue* q, unsigned int size) {
    q->data = new int[size];  // Allocate memory for the queue
    q->front = 0;             // Initialize front index
    q->back = -1;             // Initialize back index
    q->size = size;           // Set maximum capacity
    q->currentSize = 0;       // Initialize current size to 0
}

void cleanQueue(Queue* q) {
    delete[] q->data;         // Free the allocated memory
    q->data = nullptr;
    q->front = 0;
    q->back = -1;
    q->currentSize = 0;
}

void enqueue(Queue* q, unsigned int newValue) {
    if (isFull(q)) {
        std::cerr << "Queue is full!" << std::endl;
        return;
    }
    q->back = (q->back + 1) % q->size; // Circular increment for back
    q->data[q->back] = newValue;
    q->currentSize++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }
    int removedValue = q->data[q->front];
    q->front = (q->front + 1) % q->size; // Circular increment for front
    q->currentSize--;
    return removedValue;
}

bool isEmpty(Queue* q) {
    return q->currentSize == 0;
}

bool isFull(Queue* q) {
    return q->currentSize == q->size;
}
