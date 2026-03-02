'''
Think small
Solve current problem by making it smaller
'''

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0
        if n == 0:
            return 1
        
        if n < 0:
            return myPow(1/x, -n)
        
        if n%2 == 0:
            return myPow(x, n//2) ** 2
        else:
            return x * myPow(x, n//2) **2
        
