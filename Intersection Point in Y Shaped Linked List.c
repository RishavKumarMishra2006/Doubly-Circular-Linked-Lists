def getCount(head):
    count = 0
    while head:
        count += 1
        head = head.next
    return count

def intersectPoint(head1, head2):
    c1, c2 = getCount(head1), getCount(head2)
    d = abs(c1 - c2)
    if c1 > c2:
        for _ in range(d):
            head1 = head1.next
    else:
        for _ in range(d):
            head2 = head2.next
    while head1 and head2:
        if head1 == head2:
            return head1.data
        head1 = head1.next
        head2 = head2.next
    return -1
