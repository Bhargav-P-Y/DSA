class Solution {
public:
    int findMedian(vector<int>& nums, int l, int r)
    {
        vector<int> sub;
        for(int i = l;i<r;i++)
            sub.push_back(nums[i]);

        sort(sub.begin(), sub.end());
        int n = sub.size();
        return sub[(n-1)/2];
    }
    int partition(vector<int>& nums, int l, int r)
    {
        //Divide into groups of 5
        //Sort the partition of 5 eles
        //Return the median & collect the results
        //Return the median of these medians
        vector<int> medians;

        for(int i = l;i<=r;i+=5)
        {
            int end = min(i+5, r+1);
            int median = findMedian(nums, i, end);
            medians.push_back(median);
        }

        sort(medians.begin(), medians.end());
        int n = medians.size();
        return medians[(n-1)/2];
    }
    int quickSelect(vector<int>& nums, int l, int r, int target)
    {
        if(l == r) return nums[l];
        int val = partition(nums, l ,r);
        int pivotIdx = -1;

        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == val)
            {
                pivotIdx = i;
                break;
            }
        }

        swap(nums[pivotIdx], nums[r]);
        int pivot = nums[r];
        int targetIdx = l;

        //All eles greater than val must be to the left
        for(int i = l;i<r;i++)
        {
            if(nums[i] >= pivot)
                swap(nums[i], nums[targetIdx++]);
        }
        swap(nums[r], nums[targetIdx]);

        if(targetIdx == target) return nums[targetIdx];
        //Too many elements greater than it
        //search left part
        else if(targetIdx > target) 
            return quickSelect(nums, l ,targetIdx-1, target);
        else 
            return quickSelect(nums, targetIdx+1, r, target);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k-1);
    }
};
