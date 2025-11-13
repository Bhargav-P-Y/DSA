// DFS can cause stack overflow errors for large graphs

class Solution {
public:
    bool isSafe(int r, int c, int rows, int cols){
        return r>=0 && r<rows && c>=0 && c<cols;
    }
    void solve(vector<vector<char>>& board) {
        // First iterate across the edges
        // Only if a cell is an 'O'
        // Push its coordinates to the queue
        // Perform bfs

        // Get the dimensions
        int rows = board.size(), cols = board[0].size();
        queue<pair<int, int>> q;

        for(int r = 0;r<rows;r++)
        {
            if(board[r][0] == 'O')
                q.push({r, 0});
            if(board[r][cols-1] == 'O')
                q.push({r, cols-1});
        }
        for(int c = 0;c<cols;c++)
        {
            if(board[0][c] == 'O')
                q.push({0, c});
            if(board[rows-1][c] == 'O')
                q.push({rows-1, c});
        }

        // Escape the 'O' cells that are connected 
        // 4-directionally from the 
        // borders as they can't be surrounded
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            //Escape the cell
            board[r][c] = 'E';

            for(int i = 0;i<4;i++)
            {
                int nr = r + dirs[i].first;
                int nc = c + dirs[i].second;

                if(isSafe(nr, nc, rows, cols) && board[nr][nc] == 'O')
                    q.push({nr, nc});
            }
        }

        // Change 'E' cells back to 'O'
        // And 'O' cells to 'X'
        // As after we traverse all 4 directions and it is still
        // 'O' it implies it is surrounded by X's hence can be captured
        for(int r = 0;r<rows;r++)
        {
            for(int c = 0;c<cols;c++)
            {
                if(board[r][c] == 'E')
                    board[r][c] = 'O';
                else if(board[r][c] == 'O')
                    board[r][c] = 'X';
            }
        }
        
    }
};
