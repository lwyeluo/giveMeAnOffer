'''
输入一个链表，输出该链表中倒数第k个结点。
'''

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if head is None or k == 0:
            return None
        
        node = head
        final_node = ListNode(0)
        final_node.next = head
        
        i = k
        while node:
            node = node.next
            if i > 1:
                i -= 1
            else:
                final_node = final_node.next
        return final_node if final_node.next != head else None
                
