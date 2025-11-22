// Prim's Algorithm
// Choose one node
// Go n times & find the closest unvisited node
// Update distances
// Repeat n times

class Solution {
public:
    int manHat(vector<int>& a, vector<int>& b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Prim's Algorithm for MST
        int n = points.size(), cost = 0;
        vector<int> minDist(n, INT_MAX);
        vector<bool> vis(n, false);

        minDist[0] = 0;

        // Repeat n times
        for(int i = 0;i<n;i++)
        {
            int u = -1;

            // Find the closest unvisited node
            for(int j = 0;j<n;j++)
            {
                if(!vis[j] && (u == -1 || minDist[j] < minDist[u]))
                    u = j;
            }

            // Add the point to MST
            vis[u] = true;
            cost += minDist[u];
        
            // Update
            for(int v = 0;v<n;v++)
            {
                if(!vis[v])
                {
                    int dist = manHat(points[v], points[u]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }
        return cost;
    }
};
