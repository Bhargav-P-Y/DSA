/*
Start from the destination
Ways at the detination's row & column is 1

THe cell's ways = Bottom + RIght cells ways
Iterate and fill the 2D table

THen optimize space!
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> bottom(n, 1);

        for(int r = m-2;r>=0;r--)
        {
            for(int c = n-2;c>=0;c--)
            {
                bottom[c] = bottom[c] + bottom[c+1];
            }
        }

        return bottom[0];
    }
};
