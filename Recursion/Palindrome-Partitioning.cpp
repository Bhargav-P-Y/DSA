/*
From every index from start to end
Explore every index after it & check if that range forms a substring
*/

class Solution {
public:
    void recur(vector<vector<string>>& res, vector<vector<bool>>& dp,
                vector<string>& part, string& s, int idx)
    {
        //Base case:
        if(idx == s.length())
        {
            // Reached the end of a branch
            res.push_back(part);
            return;
        }

        for(int j = idx;j<s.length();j++)
        {
            if(dp[idx][j])
            {
                part.push_back(s.substr(idx,j-idx+1));
                recur(res, dp, part, s, j+1);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // Make a dp table that tells if a given 
        // substring is a palindrome or not

        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Start from len 1 to n
        // i is the start, j is the end of the substr, i+len-1
        // if s[i] & s[j] match and (j-i <= 2 || dp[i+1][j-1] == true) make it true
        for(int len = 1;len<=n;len++)
        {
            for(int i = 0;i<=n-len;i++)
            {
                int j = i+len-1;
                if( (s[i] == s[j]) && (j-i <= 2 || dp[i+1][j-1]) )
                    dp[i][j] = true;
            }
        }

        // To store the res
        vector<vector<string>> res; 

        // To store the intermediate strings
        vector<string> part; 

        // Start recursion
        recur(res, dp, part, s, 0); 
        return res;
    }
};
