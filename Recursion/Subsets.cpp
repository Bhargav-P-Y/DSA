/*
Think small -> Base case
Then consider take & not take cases

Pass by reference: Save unecessary copying
*/

class Solution {
public:
    void recur(vector<vector<int>>& res, vector<int>& nums, vector<int>& sub, int idx)
    {
        //Base case: Reached the end
        if(idx>=nums.size())
        {
            res.push_back(sub);
            return;
        }

        //Take it
        sub.push_back(nums[idx]);
        //Recurse
        recur(res, nums, sub, idx+1);
        //BackTrack
        sub.pop_back();

        //Don't take it
        recur(res, nums, sub, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //Stores all the subsets
        vector<vector<int>> res;
        //Stores intermediate subsets along the way
        vector<int> sub;
        int idx = 0;

        recur(res, nums, sub, idx);
        return res;

        
    }
};
