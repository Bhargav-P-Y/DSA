/*
Can't iterate and modify elemtns at the same time
Use an ordered map for sorted order.
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int, int> freq;
        for(int num: hand)
            freq[num]++;
        
        while(!freq.empty())
        {
            int start = freq.begin()->first;
            for(int i = 0;i<groupSize;i++)
            {
                int key = start + i;
                if(freq.find(key) == freq.end()) return false;
                freq[key] -=1;

                if(freq[key] == 0) freq.erase(key);
            }
        }
        return true;
    }
};
