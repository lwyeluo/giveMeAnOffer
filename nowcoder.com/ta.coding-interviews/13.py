'''
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
'''

# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        # write code here
        # 记录所有奇数数目
        oddCount = 0
        for val in array:
            if val & 1 == 1:
                oddCount += 1
        if oddCount == len(array):
            return array

        #  array: [1, 2, 3, 4, 5] -> oddCount = 3
        #  round 0: [1, 2, 3 (oddSucPtr, oddFinalPtr), 4, 5 (oddCurPtr)]
        #  round 1: [1, 2 (oddSucPtr), 5 (oddFinalPtr), 3, 4 (oddCurPtr)]
        #  ...
        oddCurPtr, oddFinalPtr = len(array) - 1, oddCount - 1
        oddSucPtr = oddFinalPtr
        
        # 从后往前找奇数
        while True:
            # 找最后的奇数
            while array[oddCurPtr] & 1 == 0:
                oddCurPtr -= 1
                if oddCurPtr <= oddFinalPtr:
                    return array
            print(oddSucPtr, oddFinalPtr, oddCurPtr, array)
            # 交换
            ptr, ptrVal = oddCurPtr, array[oddCurPtr]
            while ptr > oddFinalPtr + 1:
                array[ptr] = array[ptr - 1]
                ptr -= 1
            array[oddFinalPtr + 1] = array[oddSucPtr]
            array[oddSucPtr] = ptrVal

            oddSucPtr -= 1
        return array
            

# Solution 1: 新建数组
# class Solution:
#     def reOrderArray(self, array):
#         # write code here
#         odd = []
#         even = []
#         for val in array:
#             if val & 1 == 1:
#                 odd.append(val)
#             else:
#                 even.append(val)
#         return odd + even

