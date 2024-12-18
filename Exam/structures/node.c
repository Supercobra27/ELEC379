#include <stdlib.h>
#include <stdio.h>
#include "node.h"

int peek(Node* head) {
    if (head == NULL) {
        fprintf(stderr, "Error: Cannot peek, the data structure is empty.\n");
        exit(EXIT_FAILURE);  // Or return a special value like -1 or INT_MIN based on your use case
    }
    return head->data;
}