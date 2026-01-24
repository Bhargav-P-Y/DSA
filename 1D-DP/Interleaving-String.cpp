// With space optimization
// THe interleaving by defn enforces the |n-m| <=1 constraint

// Without space optimization

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if(s3.length() != n+m) return false;
        
        vector<bool> cur(m+1, false);

        // Base case
        cur[0] = true;

        // Initialize the 1st row
        for(int j = 1;j<=m;j++)
        {
            if(s2[j-1] == s3[j-1] && cur[j-1])
                cur[j] = true;
        }

        // Fill with recurrence defined
        for(int i = 1;i<=n;i++)
        {
            // Boundary case
            cur[0] = (s1[i-1] == s3[i-1]) && cur[0];

            for(int j = 1;j<=m;j++)
            {
                // Two cases
                // Either take the char at s1 or from s2
                bool cond1 = (s1[i-1] == s3[i+j-1]) && cur[j];
                bool cond2 = (s2[j-1] == s3[i+j-1]) && cur[j-1];

                cur[j] = cond1 || cond2;
                
            }
        }
        return cur[m];
    }
};



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if(s3.length() != n+m) return false;
        
        vector<bool> cur(m+1, false), nxt(m+1, false), init(m+1, false);

        // Base case
        cur[0] = true;

        // Initialize the 1st row
        for(int j = 1;j<=m;j++)
        {
            if(s2[j-1] == s3[j-1] && cur[j-1])
                cur[j] = true;
        }

        // Fill with recurrence defined
        for(int i = 1;i<=n;i++)
        {
            // Boundary case
            if(s1[i-1] == s3[i-1] && cur[0])
                nxt[0] = true;

            for(int j = 1;j<=m;j++)
            {
                // Two cases
                // Either take the char at s1 or from s2
                if(s1[i-1] == s3[i+j-1])
                    nxt[j] = nxt[j] || cur[j];

                if(s2[j-1] == s3[i+j-1])
                    nxt[j] = nxt[j] || nxt[j-1];

            }
            cur = nxt;
            nxt = init;
        }
        return cur[m];
    }
};


// Without space optimization

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if(s3.length() != n+m) return false;
        
        int MAXI = n+m+1;
        vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(m+1, {MAXI, MAXI}));

        // Base case
        dp[0][0] = {0, 0};

        // Boundary initialization cases
        for(int i = 1;i<=n;i++)
        {
            if(s1.substr(0, i) == s3.substr(0, i))
                dp[i][0].first = 1;
        }

        for(int j = 1;j<=m;j++)
        {
            if(s2.substr(0, j) == s3.substr(0, j))
                dp[0][j].second = 1;
        }

        // Fill with recurrence defined
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                // Were we right before?
                // Imp bcz if we were wrong before it doesn't amtter what we do 
                // next as it will be wrong
                if(s1[i-1] == s3[i+j-1])
                {
                    // Two cases
                    // Either take the char at s1 or from s2
                    dp[i][j].first = min(dp[i][j].first, dp[i-1][j].first);
                    dp[i][j].first = min(dp[i][j].first, dp[i-1][j].second + 1);
                }
                if(s2[j-1] == s3[i+j-1])
                {
                    dp[i][j].second = min(dp[i][j].second, dp[i][j-1].second);
                    dp[i][j].second = min(dp[i][j].second, dp[i][j-1].first+1);
                }
            }
        }
        return min(dp[n][m].first, dp[n][m].second) <= 1;
    }
};
