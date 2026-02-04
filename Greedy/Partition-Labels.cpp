class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*
        Keep track of the first seen and last seen characters
        
        Check if we arrive at the boundary
        Don't check after we go past the boundary
        
        start = 0
        first update end, end = max(end, last[s[i]-'a'])
        
        CHeck if we have arrived at the boundary
        Upate res & start
        */
        int n = s.length();
        vector<int> first(26, -1), last(26, -1), res;

        for(int i = 0;i<n;i++)
        {
            if(first[s[i]-'a'] == -1)
                first[s[i]-'a'] = i;
            last[s[i]-'a'] = i;
        }
        int start = 0, end = 0;

        for(int i = 0;i<n;i++)
        {
            end = max(end, last[s[i]-'a']);

            // We arrived at boundary
            if(i == end)
            {
                res.push_back(i - start+1);
                start = i+1;
            }
        }
        return res;
    }
};
