/* If meetings end quickly, then you can take more meetings & leave time for more
*  So first sort by ending times in ascending order
   then by start times
*
*/

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        if(a[1] == b[1]) return a[0] < b[0];
        else return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int del = 0;
        int n = intervals.size();
        int end = intervals[0][1];

        for(int i = 1;i<n;i++)
        {
            if(intervals[i][0] >= end)
                end = intervals[i][1];
            else
                del++;
        }
        return del;
        
    }
};
