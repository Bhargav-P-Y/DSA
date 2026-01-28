/*
Question your Base case!
Consider both cases: Take & No take cases
*/

class Solution {
public:
    bool recur(string& s, string& p, int i, int j, 
                vector<vector<int>>& dp)
    {
        // Base case
        if(j == p.length())
            return i == s.length();
        
        // Already computed
        if(dp[i][j] != -1)
            return dp[i][j] == 1;
        
        bool ans = false;

        // Next char in pattern is *
        if(j+1 < p.length() && p[j+1] == '*')
        {
            // Option 1: Skip it
            ans = recur(s, p, i, j+2, dp);
            // Option 2: Consider it
            if(i < s.length() && (s[i] == p[j] || p[j] == '.'))
                ans = ans || recur(s, p, i+1, j, dp);
        }
        // Normal match
        else if(i < s.length() && (s[i] == p[j] || p[j] == '.'))
            ans = recur(s, p, i+1, j+1, dp);

        dp[i][j] = ans ? 1: 0;
        return ans;
    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return recur(s, p, 0, 0, dp);
    }
};
