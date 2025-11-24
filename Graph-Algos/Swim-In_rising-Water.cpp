// BFS + Dijkstra

class Solution {
public:
    bool isSafe(int r, int c, int dim){
        return r>=0 && r<dim && c>=0 && c<dim;
    }
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int dim = grid.size(), ans = 0;
        vector<vector<int>> vis(dim, vector<int>(dim, INT_MAX));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = grid[0][0];

        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();

            int dist = t[0], r = t[1], c = t[2];

            if(r == dim-1 && c == dim -1)
            {
                ans = vis[r][c];
                break;
            }

            for(int i = 0;i<4;i++)
            {
                int nr = r + dirs[i].first;
                int nc = c + dirs[i].second;

                if(isSafe(nr, nc, dim) && vis[nr][nc] == INT_MAX)
                {
                    vis[nr][nc] = max(vis[r][c], grid[nr][nc]);
                    pq.push({vis[nr][nc], nr, nc});
                }
            }
        }
        return ans;
    }
};
