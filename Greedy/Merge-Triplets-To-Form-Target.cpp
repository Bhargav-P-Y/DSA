/*
no need to perform the actual max operations in code.
The greedy check of “does each target component exist in some valid triplet?” is sufficient.
Our local success (finding one or more target elements), can lead to overall success?
*/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool foundX = false, foundY = false, foundZ = false;

        for(auto& t: triplets)
        {
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2])
            {
                if(t[0] == target[0])
                    foundX = true;
                if(t[1] == target[1])
                    foundX = true;
                if(t[2] == target[2])
                    foundX = true;
            }
        }

        return foundX && foundY && foundZ;
    }
};
