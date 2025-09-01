def deleteNode(head, x):
    if not head:
        return None
    if x == 1:
        head = head.next
        if head:
            head.prev = None
        return head
    curr = head
    for i in range(1, x):
        curr = curr.next
    if curr.next:
        curr.next.prev = curr.prev
    if curr.prev:
        curr.prev.next = curr.next
    return head
