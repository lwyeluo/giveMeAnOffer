'''
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

还是斐波那契数列。。
'''

# -*- coding:utf-8 -*-
class Solution:
    def rectCover(self, number):
        # write code here
        array = [0, 1, 2]
        i = len(array)
        while i <= number:
            i += 1
            array.append(array[-1] + array[-2])
        return array[number]

