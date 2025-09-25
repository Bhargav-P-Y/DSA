/*
Be mindful for what's on the top!
Accordingly use min/max -> greater or without it
*/

class Solution {
public:
    int dist(const vector<int>& point)
    {
        return point[0]*point[0] + point[1]*point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        int n = points.size();

        for(int i = 0;i<k;i++)
            pq.push({ dist(points[i]), i});
        
        for(int i = k;i<n;i++)
        {
            if(pq.top().first > dist(points[i]))
            {
                pq.pop();
                pq.push({dist(points[i]), i});
            }  
        }
        vector<vector<int>> res;
        while(!pq.empty())
        {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
