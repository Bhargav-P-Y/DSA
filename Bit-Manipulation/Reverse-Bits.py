'''
See positions of bits in orginal & reversed
They are 31 - i spaces apart
'''

class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0

        for i in range(32):
            bit = (n >> i) & 1
            if bit == 1:
                res |= (1 <<(31 -i))
                
        return res
        
