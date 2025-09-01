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
struct Node* pairwiseSwap(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* curr = head->next->next;
    struct Node* prev = head;
    head = head->next;
    head->next = prev;

    while (curr && curr->next) {
        prev->next = curr->next;
        prev = curr;
        struct Node* next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}
