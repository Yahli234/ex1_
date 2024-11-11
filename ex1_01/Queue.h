#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Queue {
    int* data;       // Dynamic array to store queue elements
    int front;       // Index of the front element
    int back;        // Index of the back element
    int size;        // Maximum capacity of the queue
    int currentSize; // Current number of elements in the queue
} Queue;

void initQueue(Queue* q, unsigned int size);
void cleanQueue(Queue* q);

void enqueue(Queue* q, unsigned int newValue);
int dequeue(Queue* q);

bool isEmpty(Queue* q);
bool isFull(Queue* q);

#endif /* QUEUE_H */
