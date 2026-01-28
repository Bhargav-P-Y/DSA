// Space optimized Bottom-up Approach

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n = s.length(), m = p.length();
        vector<bool> cur(m+1, false), prev(m+1, false);

        /* 
        Base case
        Empty string & pattern is true
        Index i represents the length
        */
        prev[0] = true;
        
        // First row
        for(int j = 2;j<=m;j++)
        {
            if(p[j-1] == '*' && prev[j-2])
                prev[j] = true;
        }
        for(int i = 1;i<=n;i++)
        {
            fill(cur.begin(), cur.end(), false);
            
            for(int j = 1;j<=m;j++)
            {
                if(p[j-1] == '.' || (s[i-1] == p[j-1]))
                    cur[j] = prev[j-1];
                else if(p[j-1] == '*')
                {
                    // Skip it
                    cur[j] = cur[j-2];
                    // See if it matches
                    if(p[j-2] == '.' || p[j-2] == s[i-1])
                        cur[j] = cur[j] || prev[j];
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, false));

        /* 
        Base case
        Empty string & pattern is true
        Index i represents the length
        */
        dp[0][0] = true;
        
        // First row
        for(int j = 2;j<=m;j++)
        {
            if(p[j-1] == '*' && dp[0][j-2])
                dp[0][j] = true;
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(p[j-1] == '.' || (s[i-1] == p[j-1]))
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    // Skip it
                    dp[i][j] = dp[i][j-2];
                    // See if it matches
                    if(p[j-2] == '.' || p[j-2] == s[i-1])
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};


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
