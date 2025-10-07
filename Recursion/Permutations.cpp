/*
When to stop?: if idx == nums.size()
Mark it as visited -> Recurse -> Backtrack
*/

class Solution {
public:
    void recur(vector<vector<int>>& res, vector<int>& nums, vector<int>& sub, vector<bool>& vis)
    {
        if(sub.size() == nums.size())
        {
            res.push_back(sub);
            return;
        }

        for(int i = 0;i<nums.size();i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                sub.push_back(nums[i]);
                recur(res, nums, sub, vis);
                sub.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> sub;
        vector<bool> vis(n, false);
        recur(res, nums, sub, vis);
        return res;

        
    }
};
