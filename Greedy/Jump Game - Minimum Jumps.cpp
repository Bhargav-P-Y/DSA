class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        The longer jump I take
        The fewer jumps I will need
        */
        int jumps = 0, n = nums.size();
        int s = 0, e = 0;

        // DOn't overcount!
        // Use s < n-1, becasue at n-1 we are already
        // at the destiantion!

        while(s<n-1)
        {
            // If it's possible to reach the end
            // return 1 + no.of jumps taken so far
            if(s + nums[s] >= n-1)
                return 1 + jumps;
            
            // Current len we can jump across
            e = s + nums[s];

            // Try to find the maximum possible 
            // jump within your current reach
            int maxJump = 0, ns = 0;
            for(int i = s;i<=e;i++)
            {
                if(i+nums[i] > maxJump)
                {
                    ns = i;
                    maxJump = i + nums[i];
                }
            }
            s = ns;
            // We jumped once
            jumps++;
        }
        // Won't reach here
        return 0;
    }
};
