// To reach, stair n, we can do from stair n-1 or n-2
// So no. of ways is, the sum of the 2

class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 1 || n == 2) 
            return n;
        int p1 = 1, p2 = 2, steps = 0;

        for(int i = 2;i<n;i++)
        {
            steps = p1+p2;
            p1 = p2;
            p2 = steps;
        }
        return steps;
        
    }
};
