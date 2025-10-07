/*
Use what you already have
Sort nums to make sure duplicates are next to each other

Take a num -> Recurse -. Backtrack
Now for not take, skip over duplicates in a while loop

THen don't take
*/

class Solution {
public:
    void recur(vector<vector<int>>& res, vector<int>& candidates, vector<int>& sub, int target, int idx)
    {
        if(target == 0)
        {
            res.push_back(sub);
            return;
        }
        if(target<0 || idx >= candidates.size()) return;
        
        sub.push_back(candidates[idx]);
        recur(res, candidates, sub, target-candidates[idx], idx+1);
        sub.pop_back();

        while(idx+1 < candidates.size() && candidates[idx] == candidates[idx+1]) idx++;

        recur(res, candidates, sub, target, idx+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;

        sort(candidates.begin(), candidates.end());

        recur(res, candidates, sub, target, 0);
        return res;
    }
};
