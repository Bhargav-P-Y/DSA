/*
Initialize correctly
Coins first then amounts --> Counts only combinations -> Order doesn't matter
As a coin is used only once per amount

Amounts first then coins, then the coin can be used in different arragements

For minimum ways
dp[a] = min(dp[a], 1+ dp[a-coin]);

FOr total ways:
dp[a] += 1+ dp[a-coin]);

Becasue dp[a] already has the noTake case

FOrward iteration can resue
Backward iteration can't reuse
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);

        // Base case: For amount 0 we need 0 coins
        dp[0] = 0;

        // Try every possible coin
        for(int coin: coins)
        {
            // Go through every possible amount with it
            // Forward iteration, as we can reuse coins
            for(int a = coin;a<=amount;a++)
                // Minimum of take and don't take case
                dp[a] = min(dp[a], 1+ dp[a-coin]);
        }

        return dp[amount] != amount+1 ? dp[amount] : -1;
    }
};
