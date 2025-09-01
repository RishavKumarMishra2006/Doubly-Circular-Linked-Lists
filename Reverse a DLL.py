def reverseDLL(head):
    if not head:
        return None
    curr = head
    prev = None
    while curr:
        prev = curr.prev
        curr.prev = curr.next
        curr.next = prev
        curr = curr.prev
    return prev.prev
