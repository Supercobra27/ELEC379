#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for new node
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;  // The new node points to NULL
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, the new node is the head
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newNode;  // Add the new node at the end
    }
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // Print the data of the node
        temp = temp->next;  // Move to the next node
    }
    printf("NULL\n");
}

// Function to delete a node with a given value
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node* temp = *head;
    Node* prev = NULL;
    
    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Move the head to the next node
        free(temp);  // Free the memory of the deleted node
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("Node with value %d not found!\n", data);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);  // Free the memory of the deleted node
}

// Function to search for a node with a specific value
Node* search(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;  // Node found
        }
        temp = temp->next;
    }
    return NULL;  // Node not found
}
