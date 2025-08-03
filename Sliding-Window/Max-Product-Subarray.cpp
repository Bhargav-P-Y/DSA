/*
Go left to right & right to left 
Why?
To not neglect the last negative number & the first negative number

OR

Keep track of the minimum & maximum(store a copy)
Update later
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l2r = 1, r2l = 1;
        int n = nums.size();
        int l = 0, r = nums.size()-1;

        int maxi = INT_MIN;

        for(int i = 0;i<n;i++)
        {
            l2r *= nums[i];
            maxi = max(maxi, l2r);
            if(l2r == 0) l2r = 1;
            
            r2l *= nums[n-i-1];
            maxi = max(maxi, r2l);
            if(r2l == 0) r2l = 1;
        }

        return maxi;
        
    }
};
