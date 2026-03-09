class Solution:
    def getSum(self, a: int, b: int) -> int:
        res, carry = 0, 0
        MASK = 0xFFFFFFFF
        MAX_INT = 0x7FFFFFFF

        for i in range(32):
            bit1 = (a >> i) & 1
            bit2 = (b >> i) & 1

            sum = bit1 ^ bit2 ^ carry

            if sum:
                res |= (1 << i)

            if bit1 == 1 and bit2 == 1:
                carry = 1
            elif carry == 1 and (bit1 ^ bit2):
                carry = 1
            else:
                carry = 0
        
        # Restrict to 32 bits, becomes unsigned in the process
        res &= MASK
        
        # ^ MASK flips all 32 bits, adds the sign (invert step of 2's complemetn)
        # ~x does flip bits. In c++ or java, its flipped becasue integers are bounded
        # but in python its not bounded, so python does -(x+1)
        # ~x in Python is -(x+1) [Adds 1 and makes it negative] -> 2's complement complete
  
        return res if res <= MAX_INT else ~(res ^ MASK) 
        
