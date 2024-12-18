#ifndef _STACK_H_
#define _STACK_H_

#include "node.h"

typedef struct Stack { 
    struct Node* top;
} Stack;

void initStack(Stack* stack);
int isStackEmpty(Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);
void freeStack(Stack* stack);

#endif /* _STACK_H_ */