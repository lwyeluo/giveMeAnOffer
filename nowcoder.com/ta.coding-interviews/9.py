'''
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

f(n) = f(n - 1) + f(n - 2) + ... + f(1) = 2 * f(n - 1)
'''

# -*- coding:utf-8 -*-
class Solution:
    def jumpFloorII(self, number):
        # write code here
        array = [0, 1, 2]
        i = len(array)
        while i <= number:
            i += 1
            array.append(2 * array[-1])
        return array[number]
