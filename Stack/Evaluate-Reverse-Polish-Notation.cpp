// stoi is more robust, than atoi
// int/int will be int

class Solution {
public:
    int eval(int l, int r, string& op)
    {
        if(op == "+") return l+r;
        else if(op == "-") return l-r;
        else if(op == "*") return l*r;
        else return l/r;
    }
    bool isOp(const string& op)
    {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i =0;i<tokens.size();i++)
        {
            if(isOp(tokens[i]))
            {
                int rop = st.top(); st.pop();
                int lop = st.top(); st.pop();
                st.push(eval(lop, rop, tokens[i]));
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
