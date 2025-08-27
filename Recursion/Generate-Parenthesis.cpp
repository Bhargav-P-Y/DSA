// If strings length == 2*n, found a valid string
// If open < total_open_brackets, then open -1
// CHECK IF YOU CAN ADD A CLOSING BRACKET BEFORE ADDING THEN CHECKING!!

class Solution {
public:
    void recur(int open, int close, string s, vector<string>& res, int lim)
    {
        if(s.length() == 2*lim)
        {
            res.push_back(s);
            return;
        }
        if(open<lim)
            recur(open+1, close, s+"(", res, lim);
        if(close<open)
            recur(open, close+1, s+")", res, lim);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recur(0, 0, "", res, n);
        return res;
        
    }
};
