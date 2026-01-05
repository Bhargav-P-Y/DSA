/*
Consider every index as the center
And grow from that

Prevents repeated work
*/
class Solution {
public:
    string longestPalindrome(string s) {
        // Two cetner edge, boundary growing technique
        // Start from i  to n,
        // Nest another loop from 0 to 1
        // l = i, r = i+j
        // If s[l] == s[r]

        int n = s.length(), maxlen = 1,start = 0;

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<2;j++)
            {
                int l = i, r = i+j;

                while(l>=0 && r<n && s[l] == s[r])
                {
                    if((r-l+1) > maxlen)
                    {
                        start = l;
                        maxlen = r-l+1;
                    }
                    l--;
                    r++;
                }
            }
        }

        return s.substr(start, maxlen);
    }
};

