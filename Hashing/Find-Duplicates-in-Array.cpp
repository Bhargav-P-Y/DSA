// Mark the elements as seen, by negating its value
//If you come agin at the same spot, it's negative
// the index not the value is the duplicate

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> dups;
        int idx = 0;

        for(int i = 0;i<n;i++)
        {
            idx = abs(nums[i])-1;
            if(nums[idx] >0)
                nums[idx] *= -1;
            else
                dups.push_back(abs(nums[i]));
        }
        return dups;
        
    }
};
