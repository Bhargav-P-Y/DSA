//Another way
//Find the row using binary search
//Find the element within that row using binary search

//Or flatten the 2D array
// mid/col & mid%col

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        int left = 0, right = r*c-1, mid = 0;

        while(left<=right)
        {
            mid = left + (right-left)/2;
            int val = matrix[mid/c][mid%c];

            if(val == target) 
                return true;
            else if(val < target) 
                left = mid+1;
            else
                right = mid -1;
        }
        return false;
    }
};
