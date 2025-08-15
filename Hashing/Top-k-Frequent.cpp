//Creating an array storing value as index can take too much memory
//So? Use the size of the array as the size of the frequency array!

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Create a vector of size n
        //Indices are the frequencies
        //Values are the array elements with that frequency

        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> eles(n+1);
        vector<int> res;
        
        for(int i = 0;i<n;i++)
            mp[nums[i]]++;
        
        for(auto entry: mp)
            eles[entry.second].push_back(entry.first);
        
        for(int i = n;i>=0;i--)
        {
            for(int n: eles[i])
                res.push_back(n);
                if(res.size() == k)
                    return res;
            
        }
    }
};



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



