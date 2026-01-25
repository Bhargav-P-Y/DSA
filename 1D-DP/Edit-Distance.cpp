/*
Consider all possible final cases

Recursion + Memoization
*/

class Solution {
public:
    int recur(string& s, string& t, int i, int j, vector<vector<int>>& dp)
    {
        // Base cases
        // REached end of both, no more ops needed
        if(j == t.length() && i == s.length())
            return 0;
        
        // One still exists
        if(i == s.length())
            return t.length() -j;
        
        if(j == t.length())
            return s.length() - i;
            
        // ALready computed
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // If characters match
        // No need to make any edits
        if(s[i] == t[j])
            dp[i][j] = recur(s, t, i+1, j+1, dp);
        // Take the minimum of insert, delete and skip cases
        else
        {
            dp[i][j] = 1+ min({
                recur(s, t, i, j+1, dp),
                recur(s, t, i+1, j, dp),
                recur(s, t, i+1, j+1, dp)
            });
        }

        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return recur(word1, word2, 0, 0, dp);
        
    }
};
