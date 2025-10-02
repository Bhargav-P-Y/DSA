/* 
Maintaining a single list is hard
Break it into two
   
Get the largest from the smaller half & 
the smallest from the larger half

Insert first then rebalance
*/

class MedianFinder {
public:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() { }
    
    void addNum(int num) {
        // Insert first
        // Rebalance next

        //When we need to add the 1st element
        //Or when the element belongs to the maxHeap
        if(maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        
        //Rebalance the heaps if they get imbalanced
        if(maxHeap.size() > minHeap.size() + 1)
        {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }
        else if(minHeap.size() > maxHeap.size() +1)
        {
            int val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
        }
    }
    
    double findMedian() 
    {
        double median = 0.0;
        if(maxHeap.size() == minHeap.size())
        {
            int num1 = maxHeap.top();
            int num2 = minHeap.top();

            median = (num1 + num2)/2.0;
            return median;
        }
        return (double)(maxHeap.size() > minHeap.size()) ? maxHeap.top() : minHeap.top();
    }
};
