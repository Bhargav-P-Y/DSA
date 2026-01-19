/*
Start from the base cases
At the nth day
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*

        2 states
        0 -> buy
        1 -> sell
        
        At index i, represents the maximum 
        profit we could have made upto that point

        At every index, we can either
        1) Buy and go ahead
        2) Sell but skip the next day
        3) Do nothing and go ahead

        Recurrence relation:
        Either buy or do nothing
        dp[i][0] = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
        EIther sell or do nothing
        dp[i][1] = max(prices[i] + dp[i+2][0], dp[i+1][1]);
        */

        int n = prices.size();
        // Edge cases:
        if(n <= 1)
            return 0;

        // No point buying on the last day
        // because we can't sell
        int nnbuy = 0, nbuy = 0, nsell = prices[n-1], cbuy = 0, csell = 0;

        for(int i = n-2;i>=0;i--)
        {
            cbuy = max(-prices[i] + nsell, nbuy);
            csell = max(prices[i] + nnbuy, nsell);

            nnbuy = nbuy;
            nbuy = cbuy;
            nsell = csell;
        }

        return nbuy;
    }
};
