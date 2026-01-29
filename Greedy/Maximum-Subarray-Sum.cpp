class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Can I include this number & extend the sum
        // Or start from the cur no. afresh

        // Keep a globalMax var, to 
        // keep track of the overall maximum

        // Initialize correctly!

        int n = nums.size();
        if(n == 1) return nums[0];

        int globalMax = nums[0], curSum = nums[0];

        for(int i = 1;i<n;i++)
        {
            curSum = max(curSum+nums[i], nums[i]);
            globalMax = max(globalMax, curSum);
        }
        return globalMax;

    }
};
