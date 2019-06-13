'''
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
'''

# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if not hasattr(self, "array"):
            self.array = [0, 1, 1, 2]
        elif n < len(self.array):
            return self.array[n]

        i = len(self.array)
        while i <= n:
            i += 1
            self.array.append(self.array[-1] + self.array[-2])
        return self.array[n]
