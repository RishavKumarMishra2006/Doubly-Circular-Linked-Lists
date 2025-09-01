class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insert(head, data):
    newNode = Node(data)
    if not head:
        newNode.next = newNode
        return newNode
    curr = head
    while curr.next != head:
        curr = curr.next
    curr.next = newNode
    newNode.next = head
    return head
