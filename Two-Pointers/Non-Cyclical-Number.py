'''
Given a positive integer, replace it with the sum of the squares of its digits.
Repeat the above step until the number equals 1, or it loops infinitely in a cycle which does not include 1.
If it stops at 1, then the number is a non-cyclical number.

We can use FLoyds cycle detection algorithm
'''

class Solution:
    def sumSquares(self, num):
        total = 0

        while num > 0:
            d = num%10
            total += d**2
            num //= 10
        
        return total

    def isHappy(self, n: int) -> bool:
        slow = n
        fast = self.sumSquares(n)

        while fast != 1 and slow != fast:
            slow = self.sumSquares(slow)
            fast = self.sumSquares(self.sumSquares(fast))
            
        return fast == 1
        
        
