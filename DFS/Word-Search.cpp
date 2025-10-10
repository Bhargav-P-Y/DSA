/*
Why the 4^l, becasue each time you branch out to 4 paths
In the worst case you might explore a branch entirely 
only to find the last character mismatches then have to 
backtrack, and this can happen for the 1st 3 branches
*/

class Solution {
public:
    bool isSafe(int rows, int cols, int r, int c)
    {
        if(r>=0 && r<rows && c>=0 && c<cols)
            return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int idx)
    {
        // Base case:
        if(idx == word.length()) return true;

        // dirs array, simplifies dfs calls
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int rows = board.size(), cols = board[0].size();


        if(isSafe(rows, cols, r, c) && board[r][c] == word[idx])
        {
            //Prevents the same cell from being reused again
            board[r][c] = '#';
            for(auto& d: dirs)
            {
                if(dfs(board, word, r+d[0], c+d[1], idx+1))
                    return true;
            }
            //Backtrack, unmark the cell to the original letter
            board[r][c] = word[idx];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();

        for(int r = 0;r<rows;r++)
        {
            for(int c = 0;c<cols;c++)
            {
                if(board[r][c] == word[0])
                    if(dfs(board, word, r, c, 0))
                        return true;
            }
        }
        return false;
        
    }
};
