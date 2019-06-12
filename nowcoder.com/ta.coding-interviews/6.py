'''
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
'''

# -*- coding:utf-8 -*-
class Solution:
    def minNumber(self, array, low, high):
        if low == high:
            return array[low], False
        if low == high - 1:
            # mid will equal low!
            return array[low] if array[low] < array[high] else array[high], False
        
        mid = (low + high) // 2
        if array[low] > array[mid]:
            val, has_found = self.minNumber(array, low, mid)
            return val, True
        if array[mid] > array[high]: 
            # array[low] < array[mid]?
            val, has_found = self.minNumber(array, mid, high)
            return val, True
        
        left_val, has_found = self.minNumber(array, low, mid)
        if has_found:
            return left_val, True
        right_val, has_found = self.minNumber(array, mid, high)
        if has_found:
            return right_val, True
        return left_val if left_val < right_val else right_val, False
    
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if not rotateArray:
            return 0
        val, has_found = self.minNumber(rotateArray, 0, len(rotateArray) - 1)
        return val
        
        # Solution 1
        # if not rotateArray:
        #     return 0
        # min_val = rotateArray[0]
        # for i in range(1, len(rotateArray)):
        #     if min_val > rotateArray[i]:
        #         min_val = rotateArray[i]
        # return min_val

