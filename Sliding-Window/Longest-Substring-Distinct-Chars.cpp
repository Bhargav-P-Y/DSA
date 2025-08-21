//Keep growing the window
//Shrink it if you find a duplicate character
//Be careful while shrinking
//You might accidentally expand

//abba : Can grow if seen[s[r]] >= l is skipped

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> seen;
        int l = 0, maxlen = 0, n = s.length();

        for(int r= 0;r<n;r++)
        {
            if(seen.find(s[r]) != seen.end() && seen[s[r]] >= l)
                l = seen[s[r]]+1;
            seen[s[r]] = r;
            maxlen = max(maxlen, r-l+1);  
        }
        return maxlen;
        
    }
};

