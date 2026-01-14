/*
Backward iteration, doesn't use the same number again
Take and not take case, elegantly included

Like a 2D memo approach: THe nested loop
need to track idx and amount as the state depends on both
as tHere might be multiple ways to reach a target amount
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = 0;

        for(int val: nums)
            total += val;
        
        if(total & 1)
            return false;
        
        int target = total >>1;

        vector<bool> dp(target+1, false);

        dp[0] = true;

        // Take each val
        for(int val: nums)
        {
            for(int i = target; i>=val;i--)
            {
                dp[i] = dp[i] || dp[target - val];
            }
        }

        return dp[target];
    }
};
