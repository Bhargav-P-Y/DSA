'''
You dont multiply by the frequency of 
(qx, qy)
again, because you're already iterating over each occurrence of  it
implicitly. If you did, you'd double-count.

The query point is fixed, not present in the map. Inferred from question

Lists mutable -> so not hashable -> can't be a key
Tuple immutable -> so hashable -> can be a key
'''

class CountSquares:

    def __init__(self):
        self.points = {}

    def add(self, point: List[int]) -> None:
        self.points[tuple(point)] = self.points.get(tuple(point), 0) + 1
  
    def count(self, point: List[int]) -> int:
        res = 0

        for p in self.points:
            cond1 = abs(p[0] - point[0]) == abs(p[1] - point[1])
            cond2 = (p[0] != point[0] and p[1] != point[1])
            if cond1 and cond2:
                qx, qy = p[0], p[1]

                point1 = (point[0], qy)
                point2 = (qx, point[1])

                res += (self.points[point1] * self.points[point2])

        return res

