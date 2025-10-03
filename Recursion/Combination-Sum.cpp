/*
Take the same element again or move to the next one
Use what we have, instead of creating a new one
*/

class Solution {
public:
    void recur(vector<vector<int>>& res, vector<int>& nums, vector<int>& sub, int target, int idx)
    {
        if(target == 0)
        {
            res.push_back(sub);
            return;
        }
        if(target < 0 || idx >= nums.size()) return;
    
        sub.push_back(nums[idx]);
        recur(res, nums, sub, target - nums[idx], idx);
        sub.pop_back();

        recur(res, nums, sub, target, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // Take the element at the index
        // Don't take the element, recurse for the next index
        vector<vector<int>> res;
        vector<int> sub;
        recur(res, nums, sub, target, 0);
        return res;
        
    }
};
