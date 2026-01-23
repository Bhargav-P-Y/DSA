/*
DFS & Memoization
*/

class Solution {
public:
    bool isSafe(int r, int c, int rows, int cols){
        return r>= 0 && r<rows && c>=0 && c<cols;
    }
    int recur(int r, int c, int prev, vector<vector<int>>& dp, 
            vector<vector<int>>& matrix)
    {
        int rows = dp.size(), cols = dp[0].size();

        // Base cases:
        // 1. Out of bounds
        if(!isSafe(r, c, rows, cols) || prev >= matrix[r][c])
            return 0;
        
        // Return results if already calculated
        if(dp[r][c] != -1)
            return dp[r][c];
        
        // Explore 4 dirs
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // The shortest path will atleast be 1, not -1
        int best = 1;
        for(auto& d: dirs)
        {
            int nr = r + d.first;
            int nc = c + d.second;

            best = max(best, 1 + recur(nr, nc, matrix[r][c], dp, matrix));
        }

        return dp[r][c] = best; 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        /*
        Create a 2D dp table of size rows, cols
        Perform a dfs search with memoization

        After checking all cells return the longest path

        Base case:
        1. Out of bounds: return 0
        2. cur val is greater than the prev val: return 0
        */
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        // Find longest path
        int longest = 1;

        // Iterate through every cell
        for(int r = 0;r<rows;r++)
        {
            for(int c = 0;c<cols;c++)
                longest = max(longest, recur(r, c, -1, dp, matrix));
        }

        return longest;
    }
};
