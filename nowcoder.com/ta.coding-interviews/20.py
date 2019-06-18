'''
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
'''

# -*- coding:utf-8 -*-
class Solution:
    def push(self, node):
        # write code here
        if hasattr(self, "stack") and hasattr(self, "min_stack"):
            val = node if node < self.stack[-1] else self.stack[-1]
            self.stack.append(node)
            self.min_stack.append(val)
        else:
            self.stack = [node]
            self.min_stack = [node]
        
    def pop(self):
        # write code here
        self.stack.pop()
        self.min_stack.pop()
    def top(self):
        # write code here
        return self.stack[-1]
    def min(self):
        # write code here
        return self.min_stack[-1]
