class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def sortedInsert(head, x):
    newNode = Node(x)
    if head is None:
        return newNode
    if x <= head.data:
        newNode.next = head
        head.prev = newNode
        return newNode
    curr = head
    while curr.next and curr.next.data < x:
        curr = curr.next
    newNode.next = curr.next
    if curr.next:
        curr.next.prev = newNode
    curr.next = newNode
    newNode.prev = curr
    return head
