//A monotonic stack can also overcome O(n^2) solution
//Prevents repeated work
// Store it based on some order
//Process it all at once

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res; 
    }
};
