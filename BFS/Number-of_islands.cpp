/*
Iterate through every cell, and only if it's land
Make sure you visit all land neighbors & mark them as visited
*/

/*
Must use dfs? 
Use iterative stack dfs

Mark the point as '0' 
Push the coordinates onto the stack
Loop through all 4 neighbors & only push if it's safe & is a 1

Just switched from using a queue to a stack
*/

/*
TC: O(m*n), each cell is processed at most once
SC: O(m*n) althought he queue doesn't holl all cells simultaneously
 IN the middle of exploring a grid with all 1's say 
 the space is proportional to the grid's dim, hence we say O(m*n(
*/

class Solution {
public:
    bool isSafe(int r, int c, int rows, int cols)
    {
        if(r>=0 && r<rows && c>=0 && c<cols)
            return true;
        return false;
    }
    void bfs(vector<vector<char>>& grid, int r, int c, int& rows, int& cols)
    {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        q.push({r, c});
        while(!q.empty())
        {
            auto point = q.front();
            q.pop();

            int x = point.first, y = point.second;
            //Mark the land as vis, by changing the 1 to 0
            grid[x][y] = '0';

            for(int i = 0;i<4;i++)
            {
                int nr = x + dirs[i].first;
                int nc = y + dirs[i].second;

                if(isSafe(nr, nc, rows, cols) && grid[nr][nc] == '1')
                    q.push({nr, nc});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int isl = 0;

        for(int r = 0;r<rows;r++)
        {
            for(int c = 0;c<cols;c++)
            {
                if(grid[r][c] == '1')
                {
                    isl+=1;
                    bfs(grid, r, c, rows, cols);
                }
            }
        }
        return isl;
        
    }
};
