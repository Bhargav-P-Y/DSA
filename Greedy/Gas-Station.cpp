/*
If surplus < 0 at station i, it means that starting 
from start and traveling to i is impossible — you ran out of gas.

Now, suppose there exists some station k between start and i that could be a valid starting point.

But if you start at k, you’d have less surplus when reaching i 
than you did starting at start (because you skipped some positive contributions before k).

Since starting at start already failed at i, starting at k must also fail.

Therefore, none of the stations between start and i can be valid. The only possible candidate is i+1.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        int surplus = 0, start = 0;

        for(int i = 0;i<n;i++)
        {
            surplus += (gas[i] - cost[i]);

            if(surplus < 0)
            {
                start = i+1;
                surplus = 0;
            }
            totalGas += gas[i];
            totalCost += cost[i];
        }
        return totalGas >= totalCost ? start : -1;
    }
};
