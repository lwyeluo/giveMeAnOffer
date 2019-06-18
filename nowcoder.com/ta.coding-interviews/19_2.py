'''
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
'''

# 解法2
# -*- coding:utf-8 -*-
class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        # write code here
        
        # 每一次打印矩阵的边界，然后调整矩阵边界
        
        row, col = len(matrix), len(matrix[0])
        top, buttom, right, left = 0, row - 1, col - 1, 0
        
        out_matrix = []
        while top <= buttom and left <= right:
            # left -> right
            out_matrix += matrix[top][left : right + 1]
            # top -> buttom
            out_matrix += [matrix[i][right] for i in range(top + 1, buttom + 1)]
            if top < buttom:
                # right -> left
                out_matrix += matrix[buttom][right - 1 : left : -1]
            if left < right:
                # buttom -> top
                out_matrix += [matrix[i][left] for i in range(buttom, top, -1)]
            # 缩小边界
            top += 1; buttom -= 1; right -= 1; left += 1
        return out_matrix

# print(Solution().printMatrix([[1]]))
# print(Solution().printMatrix([[1, 2, 3, 4, 5]]))
# print(Solution().printMatrix([[1], [2], [3], [4], [5]]))
# print(Solution().printMatrix([
#     [1, 2, 3, 4],
#     [5, 6, 7, 8],
#     [9, 10, 11, 12],
#     [13, 14, 15, 16]
# ]))
