/*
Can we reach a place?
If Yes, how far can we go from there?
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0, n = nums.size();

        for(int i = 0;i<n;i++)
        {
            if(i > farthest)
                return false;
            farthest = max(farthest, i+nums[i]);
        }
        return true;
    }
};
