// Bellman-ford
// Iterate through every edge
// And update the temp copy
// After all edges update the dist array
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX), temp(n, INT_MAX);
        dist[src] = 0, temp[src] = 0;

        for(int i = 0;i<=k;i++)
        {
            for(auto edge: flights)
            {
                int s = edge[0], d = edge[1], wt = edge[2];

                // Unreachable
                if(dist[s] == INT_MAX)
                    continue;
                // Because we want to choose the updated minimum
                else if(temp[d] > dist[s] + wt)
                    temp[d] = dist[s] + wt;
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
