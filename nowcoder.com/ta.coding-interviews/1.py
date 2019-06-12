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
