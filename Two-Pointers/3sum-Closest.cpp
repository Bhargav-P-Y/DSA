//Keep track of minDiff & Absolute difference between target and sum

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        // code here
        //Fix left or right && use 2 pointers
        sort(arr.begin(), arr.end());
        int l, m, r, n = arr.size();
        int sum, minDiff = INT_MAX, res = 0;
        
        for(l = 0;l<n-2;l++)
        {
            m = l+1, r = n-1;
            
            while(m<r)
            {
                sum = arr[l] + arr[m] + arr[r];
                
                if(abs(sum-target) < minDiff)
                {
                    minDiff = abs(sum-target);
                    res = sum;
                }
                else if(abs(sum - target) == minDiff)
                    res = max(res, sum);
                
                if(sum == target) return sum;
                else if(sum < target) m++;
                else r--;
            }
        }
        return res;
    }
};
