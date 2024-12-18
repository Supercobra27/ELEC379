#ifndef _LL_H_
#define _LL_H_

#include "node.h"

Node* createNode(int data);
void insertEnd(Node** head, int data);
void display(Node* head);
void deleteNode(Node** head, int data);
Node* search(Node* head, int data);

#endif /* _LL_H_ */