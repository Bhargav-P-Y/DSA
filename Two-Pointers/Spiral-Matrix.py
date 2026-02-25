class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        left, top, right, bottom = 0, 0, len(matrix[0]) -1, len(matrix)-1

        while left <= right and top <= bottom:
            for l in range(left, right+1):
                res.append(matrix[top][l])
            top +=1
            
            for r in range(top, bottom+1):
                res.append(matrix[r][right])
            right -=1

            if left <= right:
                for b in range(right, left-1, -1):
                    res.append(matrix[bottom][b])
                bottom -=1
            
            if top <= bottom:
                for l in range(bottom, top-1, -1):
                    res.append(matrix[l][left])
                left +=1
        
        return res
        
