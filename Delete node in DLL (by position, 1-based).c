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
struct Node* deleteNodeDLL(struct Node* head, int pos) {
    if (!head) return NULL;
    struct Node* temp = head;

    for (int i = 1; temp && i < pos; i++) temp = temp->next;
    if (!temp) return head;

    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;

    if (temp->next) temp->next->prev = temp->prev;

    free(temp);
    return head;
}
