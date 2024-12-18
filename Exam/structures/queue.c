#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

// Enqueue an element to the back of the queue
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue underflow: Cannot dequeue from an empty queue\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Display the elements of the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node* current = q->front;
    printf("Queue elements: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free all nodes in the queue
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}
