'''
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
'''

# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        col_num, row_num = len(array[0]), len(array)
        
        cur_col, cur_row = col_num - 1, 0
        while cur_col >= 0 and cur_row < row_num:
            if target < array[cur_row][cur_col]:
                cur_col -= 1
            elif target > array[cur_row][cur_col]:
                cur_row += 1
            else:
                return True
        return False
