'''
Start from smaller intervals then increase
We start towards the end, becasue the recurrence checks 
THe samller interval in the right half
'''

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        newNums = [1] + nums + [1]

        dp = [[0] for _ in range(n+2)]

        for l in range(n, 0, -1):
            for r in range(l, n+1):
                for i in range(l, r+1):
                    # Pop nums[i] last, so neighbors are fixed
                    coins = newNums[l-1] * newNums[i] * newNums[r+1]
                    # The previously computed subproblems of smaller lengths
                    coins += dp[l][i-1] + dp[i+1][r]

                    dp[l][r] = max(dp[l][r], coins)
        
        return dp[1][n]
