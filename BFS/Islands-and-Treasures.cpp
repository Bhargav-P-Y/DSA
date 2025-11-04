// Think backwards!

class Solution {
public:
    bool isSafe(int r, int c, int rows, int cols){
        return r>=0 && r<rows && c>=0 && c<cols;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //Send signals from treasure to land
        // Every land cell to treasure can take a lot of time

        queue<pair<int, int>> q;
        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Traverse through the grid and add all treasure chests
        // to the queue

        for(int r = 0;r<rows;r++)
        {
            for(int c = 0;c<cols;c++)
            {
                //If it's a treasure chest
                if(grid[r][c] == 0)
                    q.push({r, c});
            }
        }

        //Process every land cell
        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0;i<4;i++)
            {
                int nr = r + dirs[i].first;
                int nc = c + dirs[i].second;

                //Out-of-Bounds or cell is -1, 0
                if(!isSafe(nr, nc, rows, cols) || grid[nr][nc] != INT_MAX)
                    continue;
                else
                {
                    grid[nr][nc] = 1+ grid[r][c];
                    // WE psuh becasue the signal must propagte
                    // from this land cell as well
                    q.push({nr, nc});
                }
            }

        }
        
    }
};
