//Find the minimum price in every iteration
//Check if you made a greater profit than last time
//Update if necessary

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, buy = prices[0], n = prices.size();

        for(int i = 1;i<n;i++)
        {
            buy = min(buy, prices[i]);
            maxProfit = max(maxProfit, prices[i]-buy);
        }
        return maxProfit;
        
    }
};
