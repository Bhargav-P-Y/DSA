//No need to store additional
//Prefix & Suffix arrays
//Use varaibles for prefix & suffix
//Resultant list doesn't count as extra memory

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n ,1);

        int pref = 1;
        for(int i = 0;i<n;i++)
        {
            res[i] = pref;
            pref *= nums[i];
        }

        int suff = 1;   
        for(int i = n-1;i>=0;i--)
        {
            res[i] *= suff;
            suff *= nums[i];
        }
        return res;    
    }
};
