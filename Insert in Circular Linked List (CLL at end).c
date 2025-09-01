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
struct Node* insertInCLL(struct Node* head, int data) {
    struct Node* node = newNode(data);
    if (!head) {
        node->next = node;
        return node;
    }
    struct Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = node;
    node->next = head;
    return head;
}
