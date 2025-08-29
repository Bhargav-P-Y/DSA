// Store it in pairs
// Sort by poistion in descending order
// Only if the car behind takes too long to reach the target
// Then add to the stack
// Watch out for integer division

class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.first > b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();

        for(int i = 0;i<n;i++)
            cars.push_back({position[i], speed[i]});
        
        sort(cars.begin(), cars.end(), comp);

        stack<float> fleet;

        for(int i = 0;i<n;i++)
        {
            float time = (float)(target-cars[i].first)/cars[i].second;
            if(fleet.empty() || time > fleet.top())
                fleet.push(time);
        }
        return fleet.size();
    }
};
