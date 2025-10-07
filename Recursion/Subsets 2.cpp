class Solution {
public:
    void recur(vector<vector<int>>& res, vector<int>& nums, vector<int>& sub, int idx)
    {
        res.push_back(sub);

        if(idx == nums.size())
            return;
        
        for(int i = idx;i<nums.size();i++)
        {
            if(i>idx && nums[i] == nums[i-1])
            {
                // i>idx -> At the same recursion level
                // Becasue we went down, now i moved ahead, but index is same
                //So same level

                // After exploring one branch, if the same number comes again
                //We would recreate the same branch
                // Hence we skip if they are the same
                continue;
            }
            sub.push_back(nums[i]);
            recur(res, nums, sub, i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;

        sort(nums.begin(), nums.end());

        recur(res, nums, sub, 0);
        return res;
    }
};
