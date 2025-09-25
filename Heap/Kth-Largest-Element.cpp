/*
Use a bounded priority queue: Great for small k

Top k elements need to be returned?
include <set>
Multiset can be used
multiset<int> ms; --> Can convert multiset into vector
Internally multiset uses RBT stores eles even duplicates in ascending order

sort in reverse?
sort(nums.rbegin(), nums.rend())

Concurrency? 
Mutex -> Lock in a bathroom door
Java -> Use synchronized

K changes dynamically?
k shrinks? --> THen pop & store in maxheap
k grows --> Retrieve the eles from the maxheap -> Stores maximum at the top

Use ML to predict the range within which k fluctuates
*/

class KthLargest {
public:
    int cap = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        
        for(auto num: nums)
        {
            if(pq.size() < cap)
                pq.push(num);
            else if(pq.top() < num)
            {
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    int add(int val) 
    {
        pq.push(val);
        if(pq.size() > cap)
            pq.pop();
        return pq.top(); 
    }
};
