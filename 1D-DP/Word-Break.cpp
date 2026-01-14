// Recursion + memoization

class Solution {
public:
    bool recur(string& s, int idx, vector<string>& wordDict, vector<int>& memo)
    {
        // Base case
        if(idx >= s.length())
            return true;
        
        if(memo[idx] == 1) return true;
        if(memo[idx] == 0) return false;
        
        // See if a word matches the substring from start
        for(auto word: wordDict)
        {
            if(s.substr(idx, word.length()) == word)
            {
                // See if the path down this is valid
                if(recur(s, idx+word.length(), wordDict))
                {
                    memo[idx] = 1;
                    return true;
                }    
            }
        }
        // Tried all possible words but no match
        memo[idx] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> memo(n, -1);

        // Start the recursive search
        return recur(s, 0, wordDict, memo);
    }
};
