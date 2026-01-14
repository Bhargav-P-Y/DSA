// DP based solution
class Solution {
public:
    int recur(vector<int>& nums, vector<int>& memo, int idx)
    {
        // Base case:
        if(idx >= nums.size())
            return 0;
        
        // If already computed return it
        if(memo[idx] != -1)
            return memo[idx];
        
        int curval = nums[idx];
        memo[idx] = 1;

        for(int i = idx+1;i<nums.size();i++)
        {
            int nxtval = nums[i];
            if(curval < nxtval)
            {
              // Don't overwrite
                memo[idx] = max(memo[idx], 1 + recur(nums, memo, i));
            }
        }

        return memo[idx];  
    }
    int lengthOfLIS(vector<int>& nums) { 
        // memo[idx] has the length of the longest subseuqence 
        // starting from idx
        int n = nums.size();
        
        vector<int> memo(n, -1);
        // Base case:
        memo[n-1] = 1;

        // recur from n-2 to 0 till n
        // Memoize results to prevent recomputation

        for(int i = n-2;i>=0;i--)
            recur(nums, memo, i);

        // Iterate and find maxlen
        int maxlen = 1;

        for(int val: memo)
            maxlen = max(maxlen, val);
        
        return maxlen;
    }
};

// Or greedy, lower_bound() solution
