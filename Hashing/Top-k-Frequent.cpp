class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Map to keep track of numbers & their frequencies
        //Iterate through the map & the first k pairs
        //Add them to the heap
        //Now check the top of the min heap
        //And only push the map's entry if it's greater
      
        unordered_map<int, int> mp;

        for(auto num : nums)
            mp[num]++;
      
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        for(auto entry : mp)
        {
            if(pq.size() < k)
                pq.push({entry.second, entry.first});
            else if(pq.top().first < entry.second)
            {
                pq.pop();
                pq.push({entry.second, entry.first});
            }
        }

        vector<int> res;
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            res.push_back(p.second);

        }
        return res;
    }

};


