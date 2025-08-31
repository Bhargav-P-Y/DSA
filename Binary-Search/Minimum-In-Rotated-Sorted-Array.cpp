//Am I sorted?
//Yes --> Return the left most element
//Am I wedged?
//Check in the wedged part

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, m = 0, r = nums.size() -1;

        while(l<r)
        {
            if(nums[r] - nums[l] > 0)
                return nums[l];
            else
            {
                m = l + (r-l)/2;
                if(nums[m] - nums[l] < 0)
                    r = m;
                else
                    l = m+1;    
            }
        }
        return nums[l];
        
    }
};
