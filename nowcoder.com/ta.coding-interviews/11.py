'''
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
'''

class Solution:
    def NumberOf1(self, n):
        # write code here
        if n < 0:
            n += 2 ** 32 # 如果int是32位
        count = 0
        while n != 0:
            count += 1
            n = n & (n - 1) # 把最右边的1变为0
        return count

# class Solution:
#     def NumberOf1(self, n):
#         # write code here
#         # n是负数时，将会无限循环（负数右移最高位补1）
#         #  所以必须预处理
#         if n < 0:
#             n += 2 ** 32 # 如果int是32位
#         count = 0
#         while n != 0:
#             if n & 1 == 1:
#                 count += 1
#             n >>= 1
#         return count
