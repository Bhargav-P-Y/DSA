/*
Max heap to get the most frequently occurring task
TO keep track of the next time, just use a deque
Push the next time at the end & check if the task at the fron can be done

No else if!, just another if

*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int time = 0;

        //Get the frequencies for each character
        for(char ch: tasks)
            freq[ch-'A']++;

        //A max heap to process the most 
        //frequently occurring character in
        //the beginning
        priority_queue<int, vector<int>> maxHeap;

        //A deque to get the avaliable tasks
        //Push freq & the time it can be processed again
        //Stores freq & next available time slot
        deque<pair<int, int>> dq;
        
        for(int i = 0;i<26;i++)
        {
            if(freq[i] > 0)
                maxHeap.push(freq[i]);
        }

        while(!maxHeap.empty() || !dq.empty())
        {
            time +=1;

            if(!maxHeap.empty())
            {
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt -= 1;
                if(cnt > 0)
                    dq.push_back({cnt, time + n});
            }
            if(!dq.empty() && time == dq.front().second)
            {
                maxHeap.push(dq.front().first);
                dq.pop_front();
            }  
        }   
        return time;      
    }
};
