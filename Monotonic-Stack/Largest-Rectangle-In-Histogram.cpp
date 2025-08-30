//Monotonically increasing stack
//Because the previous smaller is always the one behind it
//Push -1 to the stack, for easy width calculation
//If it breaks the increasing property
//The cur element is the next smaller
//The prev's prev ele is the prev smaller
//Find width & height & update area

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
       
        stack<int> st;
        st.push(-1);
        int maxArea = 0, height = 0, width = 0;

        for(int i = 0;i<n;i++)
        {
            while(st.top() != -1 && heights[st.top()] > heights[i])
            {
                height = heights[st.top()];
                st.pop();
                width = i - st.top() -1;
                maxArea = max(maxArea, height*width);
            }
            st.push(i);
        }
        //To process the remaining buildings in non-decreasing order
        while(st.top() != -1)
        {
            height = heights[st.top()];
            st.pop();
            width = n - st.top() -1;
            maxArea = max(maxArea, height*width); 
        }
        return maxArea;
    }
};
