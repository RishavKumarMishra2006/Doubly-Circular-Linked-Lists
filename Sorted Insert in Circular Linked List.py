def sortedInsert(head, data):
    newNode = Node(data)
    if not head:
        newNode.next = newNode
        return newNode
    curr = head
    if data < head.data:
        while curr.next != head:
            curr = curr.next
        curr.next = newNode
        newNode.next = head
        return newNode
    while curr.next != head and curr.next.data < data:
        curr = curr.next
    newNode.next = curr.next
    curr.next = newNode
    return head
