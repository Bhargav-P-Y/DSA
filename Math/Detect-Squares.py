'''
The query point is fixed, not present in the map. So freq is 0
Inferred from question

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

        for p in self.points: # WE ITERATE ACROSS the MAP
            cond1 = abs(p[0] - point[0]) == abs(p[1] - point[1])
            cond2 = (p[0] != point[0] and p[1] != point[1])
            if cond1 and cond2:
                qx, qy = p[0], p[1]

                point1 = (point[0], qy)
                point2 = (qx, point[1])
                f1 = self.points.get(point1, 0)
                f2 = self.points.get(point2, 0)

                res += (f1 * f2 * self.points[p])  # SO We need to count the diagonal point's freq as well

        return res
