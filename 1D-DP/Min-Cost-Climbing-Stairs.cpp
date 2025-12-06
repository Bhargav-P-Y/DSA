// Start small, with base cases
// Then build up

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int p2 = cost[0], p1 = cost[1], res = 0;

        for(int i = 2;i<n;i++)
        {
            res = cost[i] + min(p2, p1);
            p2 = p1;
            p1 = res;
        }
        return min(p1, p2);
    }
};
