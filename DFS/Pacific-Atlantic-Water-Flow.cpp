// Reverse the path!

class Solution {
public:
    bool isSafe(int r, int c, int rows, int cols){
        return r>=0 && r<rows && c>=0 && c<cols;
    }
    void dfs(vector<vector<bool>>& vis, vector<vector<int>>& heights, int r, int c)
    {
        // Mark the current cell's coordinates as true
        vis[r][c] = true;
        int rows = vis.size(), cols = vis[0].size();

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0;i<4;i++)
        {
            int nr = r + dirs[i].first;
            int nc = c + dirs[i].second;

            if(isSafe(nr, nc, rows, cols) && (heights[r][c] <= heights[nr][nc]) && !vis[nr][nc])
                dfs(vis, heights, nr, nc);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // dfs solution
        // pacific grid & atlantic grid
        // only if both pacific & atlantic is true
        // push it into the res
        // start from edges and do dfs
        // reverse the search
        // if isSafe & nr,nc >= r, c 
        // pacific or atlantic is true
        int rows = heights.size(), cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        vector<vector<int>> res;

        for(int r = 0;r<rows;r++)
        {
            dfs(pacific, heights, r, 0);
            dfs(atlantic, heights, r, cols-1);
        }
        for(int c = 0;c<cols;c++)
        {
            dfs(pacific, heights, 0, c);
            dfs(atlantic, heights, rows-1, c);
        }

        for(int r = 0;r<rows;r++)
        {
            for(int c = 0;c<cols;c++)
            {
                if(pacific[r][c] && atlantic[r][c])
                    res.push_back({r,c});
            }
        }
        return res;
        
    }
};
