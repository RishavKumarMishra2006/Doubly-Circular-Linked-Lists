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
int getLength(struct Node* head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

int getIntersection(struct Node* head1, struct Node* head2) {
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    int diff = abs(l1 - l2);

    if (l1 > l2) while (diff--) head1 = head1->next;
    else while (diff--) head2 = head2->next;

    while (head1 && head2) {
        if (head1 == head2) return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}
