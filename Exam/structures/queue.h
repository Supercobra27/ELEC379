#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "node.h"

#include <stdbool.h>

// Define the queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
void initQueue(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void displayQueue(Queue* q);
void freeQueue(Queue* q);

#endif /* _QUEUE_H_ */