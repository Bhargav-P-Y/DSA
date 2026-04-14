class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        '''
        Why pref = {0:1}?
        
        before we start, we've seen a cumulative sum of 0 exactly once.”
        That way, if the running sum itself equals k, 
        the subtraction curSum - k = 0 
        will correctly match this baseline and 
        count the subarray starting at index 0.

        By doing so, we can skip the if curSum == k check
        '''
        curSum, res = 0, 0
        pref = {0: 1}

        for num in nums:
            curSum += num
            if curSum -k in pref:
                res += pref[curSum-k]
            
            pref[curSum] = pref.get(curSum, 0) +1
        
        return res

        
