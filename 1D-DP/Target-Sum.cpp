/*
Approach 1
Recursion + Memoization
Store the subproblems actually calculated!

What parameters change, store based on them
Here its index & current running sum
*/

class Solution {
public:
    int recur(int idx, int sum, int target, vector<int>& nums,
            unordered_map<int, unordered_map<int, int>>& dp)
    {
        int n = nums.size();
        // Base case
        if(idx == n)
            return target == sum ? 1 : 0;

        if(dp[idx].count(sum))
            return dp[idx][sum];
          
        int addWays = recur(idx+1, sum-nums[idx], target, nums, dp) 
        int subWays = recur(idx+1, sum+nums[idx], target, nums, dp);
        
        return dp[idx][sum] = addWays + subWays;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        // Memo table to prevent recomputation
        unordered_map<int, unordered_map<int,int>> dp;

        /*
        Outer key: idx
        Inner key: sum
        Value: number of ways 
        */
        return recur(0, 0, target, nums, dp);
    }
};

/* Approach 2
Use what is given

S = num(P) + num(N) 
target = num(P) + num(N)

SO num(P) = S + target /2
Find positive combos to make that, fill negative nums in those ways
return no. of positive combos
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = 0;

        for(int num: nums)
            total += num;
        
        // If odd or out of range --> 0
        if((total + target)%2 != 0 || abs(target) > total)
            return 0;
        
        // Standard subset sum
        
        int subSum = (total+target)/2;
        vector<int> dp(subSum+1, 0);

        dp[0] = 1;

        for(int num: nums)
        {
            for(int j = subSet;j>=num;j--)
                dp[j] += dp[j-num];
        }

        return dp[subSum];

    }
};
