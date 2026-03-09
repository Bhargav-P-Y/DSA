class Solution:
    def reverse(self, x: int) -> int:
        sign, rev = 1, 0


        if x < 0:
            sign = -1

         # IMP! Otherwise // and % will be wrong
         x = abs(x)
        
        while x != 0:
            digit = x %10
            rev = (rev*10) + digit
            x //= 10
        
        ans = rev*sign

        MAX_INT = 0x7FFFFFFF
        MIN_INT = ~(MAX_INT)

        if MIN_INT <= ans <= MAX_INT:
            return ans
        else:
            return 0
        

        

        
