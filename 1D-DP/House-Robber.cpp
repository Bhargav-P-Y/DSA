// Start small
// Then increase

class Solution {
public:
    int rob(vector<int>& nums) {
        // find the size
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        /*
        Now start from 2
        At 2, consider
        nums[2] + p2 or p1
        Then propagte till the end
        */
        int p2 = nums[0], p1 = max(nums[0], nums[1]), maxi = 0;

        for(int i = 2;i<n;i++)
        {
            maxi = max(nums[i] + p2, p1);
            p2 = p1;
            p1 = maxi;
        }
        return p1;
        
    }
};
