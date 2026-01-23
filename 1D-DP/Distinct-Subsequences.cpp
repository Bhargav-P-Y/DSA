// Start with recursion
// THen do memoization

class Solution {
public:
    long recur(string& s, string& t, int i1, int j1,
            vector<vector<long>>& dp)
    {
        // Reached end of t
        if(j1 == t.length())
            return 1;

        // Base cases
        if(i1 == s.length())
            return 0;
        
        // ALready computed return it
        if(dp[i1][j1] != -1)
            return dp[i1][j1];

        // Characters match
        if(s[i1] == t[j1])
            // Move both ahead and try if there are 
            // other future characters that match
            dp[i1][j1] = recur(s, t, i1+1, j1+1, dp) + recur(s, t, i1+1, j1, dp);
        // Consider the skip case
        else
            dp[i1][j1] = recur(s, t, i1+1, j1, dp);

        return dp[i1][j1];
    }
    int numDistinct(string s, string t) 
    {
        int n = s.length(), m = t.length();
        vector<vector<long>> dp(n, vector<long>(m, -1));
        return recur(s, t, 0, 0, dp);

    }
};
