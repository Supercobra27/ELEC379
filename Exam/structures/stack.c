#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack* stack){
    stack->top = NULL;
}

int isStackEmpty(Stack* stack){
    return stack->top == NULL;
}

void push(Stack* stack, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    if ( node == NULL ){
        perror("Failed to allocate memory for the stack node");
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        perror("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);

    return popped;
}

void freeStack(Stack* stack) {
    while (!isStackEmpty(stack)) {
        pop(stack);
    }
}