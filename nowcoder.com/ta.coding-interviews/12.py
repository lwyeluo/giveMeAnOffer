'''
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方

分析：
	10^0b1101 = 10^0b0001 * 10^0b0100 * 10^0b1000
	10^0b0010 = (10 ^ 2) ^ 0b01
'''

class Solution:
    def Power(self, base, exponent):
        # write code here
        exp = exponent
        if exponent == 0:
            return 1
        elif exponent < 0:
            exp = -exponent
        
        ret = 1
        while exp != 0:
            if exp & 1 == 1:
                ret = ret * base
            exp >>= 1
            base *= base
        return ret if exponent > 0 else 1/ret
