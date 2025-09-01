#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;   // for DLL
};

// For multi-level linked list flattening
struct NodeChild {
    int data;
    struct NodeChild* next;
    struct NodeChild* bottom;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
struct Node* reverseDLL(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* curr = head;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) head = temp->prev;
    return head;
}
