//Check if it wasn't part of a pevious sequence!
//Only then keep checking for the next number

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;

        int maxlen = 1, len =1;
        unordered_set<int> seen;
        int cnt = 0;

        for(auto num: nums)
            seen.insert(num);
           
        for(auto num: seen)
        {
            //IMPORTANT!!
            if(!seen.count(num-1))
            {
                cnt = num;
                while(seen.count(cnt+1))
                    cnt++;
                maxlen = max(maxlen, cnt-num+1);
            }
        }
        return maxlen;
        
    }
};
