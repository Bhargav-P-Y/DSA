'''
XOR, identical things cancel out
'''

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0

        for i in range(len(nums)):
            res ^= (i+1)
            res ^= (nums[i])
        
        return res
        
