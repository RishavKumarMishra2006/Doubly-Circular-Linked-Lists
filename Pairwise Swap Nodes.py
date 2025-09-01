def pairwiseSwap(head):
    if not head or not head.next:
        return head
    prev = None
    curr = head
    head = head.next
    while curr and curr.next:
        nxt = curr.next
        curr.next = nxt.next
        nxt.next = curr
        if prev:
            prev.next = nxt
        prev = curr
        curr = curr.next
    return head
