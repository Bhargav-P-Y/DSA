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

        # Sort based on QUERIES
        s_queries = sorted([(q, idx) for idx, q in enumerate(queries)])
        # Helps you decide when to include a query
        # if start time <= q
        intervals.sort(key = lambda p: p[0])
        i, n = 0, len(intervals)

        res = [-1] * len(queries)
        times = []

        for q, idx in s_queries:
            while i < n and intervals[i][0] <= q:
                l, r = intervals[i]
                dur = r - l + 1
                heapq.heappush(times, (dur, intervals[i][1]))
                i +=1  
    
            while times and times[0][1] < q:
                heapq.heappop(times)
            
            if times:
                res[idx] = times[0][0]
            
        return res
