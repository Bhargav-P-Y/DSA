//DFS implementaion
/* FOr dfs, only if the grid is
      a 1, call dfs passing area as 0
      Base case, if a cell is unsafe or 0, return 0
      Otherwise increase area by 1 and call dfs in all 4 directions
      Don't; forget to mark it as 0!
      Pass area by refrerence and increment only after the safety & 1 check
      Finally return the area

      Comparet he current area with maxArea =, update accordingly
    */
    int dfs(vector<vector<int>>& grid, int r, int c, int& area)
    {
        if(!isSafe(r, c, grid.size(), grid[0].size())) return 0;
        if(grid[r][c] == 0) return 0;

        area+=1;
        grid[r][c] = 0;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0;i<4;i++)
            dfs(grid, r+dirs[i].first, c+dirs[i].second, area);
        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int maxArea = 0;

        // Iterate through every cell
        for(int r = 0;r<rows;r++)
        {
            for(int c = 0;c<cols;c++)
            {
                if(grid[r][c] == 1)
                {
                    int area = 0;
                    //For bfs just remove the area parameter
                    area = dfs(grid, r, c, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
