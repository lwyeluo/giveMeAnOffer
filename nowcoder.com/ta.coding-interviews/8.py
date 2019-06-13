'''
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

实际上就是斐波那契数列。
'''

# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        # write code here
        self.array = [0, 1, 2]
        i = len(self.array)
        while i <= number:
            self.array.append(self.array[i - 1] + self.array[i - 2])
            i += 1
        return self.array[number]
