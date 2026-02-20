class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        '''
        Doing a linear scan repeatedly is too time-consuming
        So sort the intervals first by start times: 
        Helps you figure out when to add
        
        Use a heap to store intervals by their duration -> Process the shortest duration task

        Decide when to add queries, start_i <= q
        & to remove them, end_i < q
        '''
        queries.sort()
        # Helps you decide when to include a query
        # if start time <= q
        intervals.sort(key = lambda p: p[0])
        n = len(queries)

        times, res = [], []

        for q in queries:
            while i < n and intervals[i][0] <= q:
                l, r = intervals[i]
                dur = r - l + 1
                heapq.heappush(times, (dur, intervals[i][1]))
                i +=1  
    
            while len(times) > 0 and times[0][1] < q:
                heapq.heappop(times)
            
            if len(times) > 0:
                res.append(times[0][0])
            else:
                res.append(-1)
            
        return res
