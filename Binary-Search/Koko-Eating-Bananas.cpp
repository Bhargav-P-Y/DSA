//Find your search space!
//Use binary search
//Watch p/k + p%k won't work always!
// 10/4 + 10%4 ---> Fails!

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini = 1, maxi = piles[0];
        int n = piles.size();
        int bans = 0;

        for(int i = 1;i<n;i++)
        {
            if(piles[i] > maxi)
                maxi = piles[i];
        }
        int ans = maxi;

        while(mini <= maxi)
        {
            bans = mini + (maxi - mini)/2;
            int cnt = 0;
            for(auto p : piles)
            {
                if(p%bans == 0)
                    cnt += p/bans;
                else
                    cnt += (p/bans) +1;
            }
                
            if(cnt > h)
                mini = bans+1;
            else
            {
                ans = min(ans, bans);
                maxi = bans-1;
            } 
        }
        return ans;
    }
};
