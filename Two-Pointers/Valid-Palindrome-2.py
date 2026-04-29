'''
We need to do the 2 pointer palindrome check
If there is a mismatch
We need to check if skipping right or left, makes it match

If it doesn't return false
'''

class Solution:
    def isPalin(self, s: str, l: int, r: int) -> bool:
        while l<r:
            if s[l] != s[r]:
                return False
            else:
                l+=1
                r-=1
        
        return True

    def validPalindrome(self, s: str) -> bool:
        
        l, r = 0, len(s) -1

        while l<r:
            if s[l] == s[r]:
                l+=1
                r-=1
            else:
                return self.isPalin(s, l+1, r) or self.isPalin(s, l, r-1)
                
        return True 


        
