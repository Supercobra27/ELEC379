#ifndef _NODE_H_
#define _NODE_H_

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int peek(Node* node);
#endif /* _NODE_H_ */