//Keep growing the window if product is less than k
//Shrink if >= k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, prod = 1, l = 0, r= 0;
        if(k<=1) return 0;

        while(r<nums.size())
        {
            prod *= nums[r];
            while(prod >= k)
            {
                prod /= nums[l];
                l++;
            }
                
            cnt += (r-l+1);
            r++;
        }
        return cnt;
        

        
    }
};
