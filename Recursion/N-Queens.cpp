// If a path isn't feasible, 
// Stop doing it, go back

class Solution {
public:
    void recur(vector<vector<string>>& res, vector<string>& board, 
            int& cols, int& diag1, 
            int& diag2, int r)
    {
        //Base case
        if(r == board.size())
        {
            res.push_back(board);
            return;
        }

        int c = 0;
        //Check every col

        for(c = 0;c<board.size();c++)
        {
            if( ((cols>>c) & 1) || ((diag1 >> r-c) & 1) || ((diag2>>r+c)&1))
                continue;
            else
            {
                board[r][c] = 'Q'; // Mark the queen
                cols |= 1<<c;
                diag1 |= 1<< r-c;
                diag2 |= 1<<r+c;

                recur(res, board, cols, diag1, diag2, r+1);

                board[r][c] = '.'; //Backtrack
                cols &= ~(1<<c);
                diag1 &= ~(1<<r-c);
                diag2 &= ~(1<<r+c);
            }
        }
        if(r<board.size() && c== board.size())
            return; //Reached a dead end
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        
        int cols, diag1, diag2;

        recur(res, board, cols, diag1, diag2, 0);

        return res;
        
    }
};
