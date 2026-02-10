'''
Earliest start time & Latest end time while merging
THen finally insert
'''
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []

        i, n = 0, len(intervals)

        # Insert all intervals before the new one
        while i<n and intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i+=1

        # Merge overlapping intervals
        while i<n and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i+=1
        res.append(newInterval)

        # Insert intervals after newInterval ends
        while i < n:
            res.append(intervals[i])
            i+=1
        return res
