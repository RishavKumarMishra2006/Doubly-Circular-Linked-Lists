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
struct NodeChild* merge(struct NodeChild* a, struct NodeChild* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->bottom = merge(a->bottom, b);
        return a;
    } else {
        b->bottom = merge(a, b->bottom);
        return b;
    }
}

struct NodeChild* flatten(struct NodeChild* root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}
