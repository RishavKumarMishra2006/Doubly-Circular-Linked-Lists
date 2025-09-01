class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.bottom = None

def merge(a, b):
    if not a:
        return b
    if not b:
        return a
    if a.data < b.data:
        result = a
        result.bottom = merge(a.bottom, b)
    else:
        result = b
        result.bottom = merge(a, b.bottom)
    result.next = None
    return result

def flatten(root):
    if not root or not root.next:
        return root
    root.next = flatten(root.next)
    root = merge(root, root.next)
    return root
