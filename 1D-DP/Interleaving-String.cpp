// With space optimization
// THe interleaving by defn enforces the |n-m| <=1 constraint

// 1 1D array

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

// 3 1D arrays

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
