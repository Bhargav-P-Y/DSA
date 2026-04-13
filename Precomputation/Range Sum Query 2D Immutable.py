class NumMatrix:
    '''
    We need to precompute but do it differently
    Consider the top portion & left portion while building the array
    Remove the top left corner as we double counted

    For the prefix sum, remove the top & left portions, but add the top left corner
    As we reduced it twice
    '''

    def __init__(self, matrix: List[List[int]]):
        # Checks for [] & [[]] cases
        if not matrix or not matrix[0]:
            return

        rows, cols = len(matrix), len(matrix[0])
        self.pref = [[0] * (cols+1) for _ in range(rows+1)]

        # Build the 2D prefix array
        for r in range(1, rows+1):
            for c in range(1, cols+1):
                self.pref[r][c] = matrix[r-1][c-1] + self.pref[r-1][c] + self.pref[r][c-1] - self.pref[r-1][c-1]
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (self.pref[row2+1][col2+1] - 
                self.pref[row1][col2+1] - 
                self.pref[row2+1][col1] + 
                self.pref[row1][col1])
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
