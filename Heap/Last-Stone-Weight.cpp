/*
Choose between max or min heap
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;

        for(auto s: stones)
            pq.push(s);
            
        while(pq.size()>1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(y > x)
                pq.push(y-x);
        }
        return (pq.size() == 1) ? pq.top() : 0;
        
    }
};
