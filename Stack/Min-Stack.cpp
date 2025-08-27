//The trick works becasue values are BETWEEN INT_MIN & INT_MAX
//Otherwise, you need to push pairs of elements
//THe element & the current minimum element found so far

class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        stack<long long> st;
        mini = LLONG_MAX;
    }
    
    void push(long long val) {
        if(st.empty())
        {
            mini = val;
            st.push(val);
        }
        else if(val < mini)
        {
            st.push(2LL*val-mini);
            mini = val; 
        }
        else
            st.push(val);
    }
    
    void pop() {
        long long tp = st.top();
        if(tp < mini)
            mini = 2LL*mini - tp;
        st.pop();
    }
    
    int top() {
        if(st.top() < mini)
            return mini;
        return st.top();
        
    }
    
    int getMin() {
        return mini;
        
    }
};
