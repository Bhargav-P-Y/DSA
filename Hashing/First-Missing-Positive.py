class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        '''
        I could try inserting all eles in a set and check from num = 2 
        onwards, does num-1 exist, if it does move ahead
        otherwise that's missing

        Creating a set is O(n) space, so I need to reuse space
        I think I should use the input array nums

        Use the array as a hashmap
        Focus on what matters

        The Solution: Just flip the order on the left side:
        nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        By putting the complex index nums[nums[i]-1] first, Python evaluates 
        that index using the original nums[i] before nums[i] gets updated.
        '''
        n = len(nums)

        for i in range(n):
            while (0 < nums[i] <= n) and (nums[i] != nums[nums[i]-1]):
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        
        for i in range(n):
            if nums[i] - 1 != i:
                return i+1
        
        return n+1
        
