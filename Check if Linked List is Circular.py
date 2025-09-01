def isCircular(head):
    if not head:
        return True
    curr = head.next
    while curr and curr != head:
        curr = curr.next
    return curr == head
