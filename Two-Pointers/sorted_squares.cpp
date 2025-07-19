// The ends have the greatest numbers, use l & r, square, compare insert from end

vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size()-1, idx = r;
        int lsq = 0, rsq = 0;

        vector<int> res(r+1, 0);
        while(l<=r)
        {
            lsq = nums[l]*nums[l];
            rsq = nums[r]*nums[r];

            if(lsq>rsq)
            {
                res[idx] = lsq;
                l++;
            }
            else
            {
                res[idx] = rsq;
                r--;
            }
            idx--;
        }

        return res;
    }
