'''
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
'''

# 解法1

# -*- coding:utf-8 -*-
class Solution:
    def nextDirection(self):
        self.cur_dir = (self.cur_dir + 1) % 4
    
    # n: row, m: col
    def nextNumber(self, n_idx, m_idx):
        is_valid = False
        if self.cur_dir % 2 == 0: # right/left
            m_idx += (1 - self.cur_dir)
            is_valid = m_idx >= 0 and m_idx < self.m
        else: # down/up
            n_idx += (2 - self.cur_dir)
            is_valid = n_idx >= 0 and n_idx < self.n
        return (True, n_idx, m_idx) if is_valid else (False, -1, -1)
        
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        # write code here
        out_num = []
        self.n, self.m = len(matrix), len(matrix[0])
        visited = [[False] * self.m for i in range(self.n)]

        self.right, self.down, self.left, self.up = 0, 1, 2, 3
        self.cur_dir = self.right
        
        i, j = 0, 0
        visited[0][0] = True
        out_num.append(matrix[0][0])
        while True:
            is_valid, n_idx, m_idx = self.nextNumber(i, j)
            if (not is_valid) or (visited[n_idx][m_idx]):
                # 没有越界且未访问过
                #  调整方向，再一次查找，若还是访问过，则搜索结束
                self.nextDirection()
                is_valid, n_idx, m_idx = self.nextNumber(i, j)
                if visited[n_idx][m_idx]:
                    break
            
            i, j = n_idx, m_idx
            out_num.append(matrix[i][j])
            visited[i][j] = True
        return out_num
                
# output = Solution().printMatrix([
#     [1, 2, 3, 4],
#     [5, 6, 7, 8],
#     [9, 10, 11, 12],
#     [13, 14, 15, 16]
# ])

# print(output)
