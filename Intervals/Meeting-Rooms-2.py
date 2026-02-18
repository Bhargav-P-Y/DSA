'''
As meetings start, increment rooms
Keep track of overall maximum encountered
'''

"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        starts, ends = [], []

        for itr in intervals:
            starts.append(itr.start)
            ends.append(itr.end)
        
        starts.sort()
        ends.sort()

        rooms, maxi = 0, 0
        s, e = 0, 0
        n = len(starts)

        while s < n:
            if starts[s] < ends[e]:
                rooms +=1
                maxi = max(maxi, rooms)
                s+=1
            else:
                rooms-=1
                e+=1
        
        return maxi
        
