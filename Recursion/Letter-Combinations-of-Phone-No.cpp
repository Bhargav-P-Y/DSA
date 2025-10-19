/*

TC: O(n*4^n)
SC: O(n)
*/

class Solution {
public:
    void recur(vector<string>& res, string& digits, 
               unordered_map<char, string>& mp, string& comb, int idx)
    {
        //Base case: When we reach the end of string
        if(idx == digits.length())
        {
            res.push_back(comb);
            return;
        }

        for(auto ch: mp[digits[idx]])
        {
            comb.push_back(ch);
            recur(res, digits, mp, comb, idx+1);
            comb.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        //To store all combinations
        vector<string> res;
        
        //Edge case: When digits is empty, return an empty vector
        if(digits.empty())
            return res;


        unordered_map<char, string> mp;

        // Map digits to their corresponsing letters
        mp['2'] = "abc", mp['3'] = "def", mp['4'] = "ghi";
        mp['5'] = "jkl", mp['6'] = "mno", mp['7'] = "pqrs";
        mp['8'] = "tuv", mp['9'] = "wxyz";


        //A string that is used while generating all combinations
        string comb = "";

        //Start the recursion
        recur(res, digits, mp, comb, 0);
        return res;
        
    }
};
