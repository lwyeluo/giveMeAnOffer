'''
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
'''

# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        
        # Solution 3
        tmpList = list(s)
        oldLen = len(tmpList)
        spaceNum = 0
        for i in range(0, oldLen):
            if tmpList[i] == ' ':
                spaceNum += 1
        newLen = oldLen + spaceNum * 2
        tmpList += '\0' * (spaceNum * 2)
        
        newPtr = newLen - 1
        for i in range(oldLen, 0, -1):
            if tmpList[i - 1] == ' ':
                tmpList[newPtr] = '0'
                tmpList[newPtr - 1] = '2'
                tmpList[newPtr - 2] = '%'
                newPtr -= 3
            else:
                tmpList[newPtr] = tmpList[i - 1]
                newPtr -= 1
        return "".join(tmpList)
        
        # Solution 2
        # ret_str = ""
        # for i in range(0, len(s)):
        #     if s[i] == ' ':
        #         ret_str += '%20'
        #     else:
        #         ret_str += s[i]
        # return ret_str
        
        # Solution 1
        # return s.replace(' ', '%20')
