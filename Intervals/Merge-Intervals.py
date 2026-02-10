'''
In place version
Don't forget to overwrite the interval
Move ahead before overwriting it
'''
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        idx = 0

        for i in range(1, len(intervals)):
            end = intervals[idx][1]
            start = intervals[i][0]

            # if there is no overlap
            if end < start:
                idx+=1  # IMP!
                intervals[idx] = intervals[i]  # Don't forget!
                
            # if there is overlap extend it
            else:
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1])
        
        return intervals[:idx+1]   
