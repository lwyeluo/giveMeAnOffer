'''
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
'''

# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        # write code here
        ptr1, ptr2 = pHead1, pHead2
        final_list = ListNode(0)
        tmp_node = final_list
        while ptr1 or ptr2:
            if not ptr1:
                tmp_node.next = ListNode(ptr2.val)
                ptr2 = ptr2.next
                tmp_node = tmp_node.next
                continue
            if not ptr2:
                tmp_node.next = ListNode(ptr1.val)
                tmp_node = tmp_node.next
                ptr1 = ptr1.next
                continue
                
            val1 = ptr1.val
            val2 = ptr2.val
            
            if val1 <= val2:
                ptr1 = ptr1.next
                tmp_node.next = ListNode(val1)
            else:
                ptr2 = ptr2.next
                tmp_node.next = ListNode(val2)
            tmp_node = tmp_node.next
        return final_list.next
            
