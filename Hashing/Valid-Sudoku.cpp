//(r/3)*3 + c/3 to uniquely identify subgrids
//Every elemetn inside the arr, acts as a separate row of 9 elements
//Saves a lot of space!
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int sqr[9] = {0};
        int val = 0, idx= 0;

        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] == '.') 
                    continue;
                val = board[i][j] -'1';
                idx = i/3;
                idx = idx*3 + j/3;

                if(rows[i] & 1<<val || cols[j] & 1<<val || sqr[idx] & 1<<val)
                    return false;
                else
                {
                    rows[i] |= 1<<val;
                    cols[j] |= 1<<val;
                    sqr[idx] |= 1<<val;
                }
            }
        }
        return true;
    }
};
