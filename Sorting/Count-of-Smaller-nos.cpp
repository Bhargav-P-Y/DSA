//Use merge step of merge sort
//Keep track of right elements smaller than the curretn one

//1. Number & index
// MergeSort + Merge + Count

class Solution {
public:
    void merge(vector<pair<int, int>>& idx_nums, int low, int mid, int high, vector<int>& counts)
    {
        vector<pair<int, int>> merged;
        int i = low, j= mid+1;
        int smalls = 0;

        while(i<=mid && j<=high)
        {
            if(idx_nums[i] <= idx_nums[j])
            {
                counts[idx_nums[i].second] += smalls;
                merged.push_back({idx_nums[i].first, idx_nums[i].second});
                i++;
            }
            else
            {
                smalls++;
                merged.push_back({idx_nums[j].first, idx_nums[j].second});
                j++;
            }
        }
        while(i<=mid)
        {
            counts[idx_nums[i].second] += smalls;
            merged.push_back({idx_nums[i].first, idx_nums[i].second});
            i++;
        }
        while(j<=high)
        {
            merged.push_back({idx_nums[j].first, idx_nums[j].second});
            j++;
        }

        for(int k = 0;k<merged.size();k++)
            idx_nums[low+k] = merged[k];
    }
    void mergeSort(vector<pair<int, int>>& idx_nums, int low, int high, vector<int>& counts)
    {
        if(low>=high) return;

        int mid = low + (high-low)/2;

        mergeSort(idx_nums, low, mid, counts);
        mergeSort(idx_nums, mid+1, high, counts);
        merge(idx_nums, low, mid, high, counts);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int, int>> idx_nums(n);

        for(int i = 0;i<n;i++)
            idx_nums[i]  ={nums[i], i};

        mergeSort(idx_nums, 0, n-1, counts);
        return counts;
    }
};
