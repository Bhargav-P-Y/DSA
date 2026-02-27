'''
Reuse the matrix
Check first row & col first and keep them in separate variables
Mark
Set inner matrix to zeros
Set the first row & col to 0 if needed
'''

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = len(matrix), len(matrix[0])
        
        # Step 1: Check if first row and first column have zeros
        first_row = any(matrix[0][c] == 0 for c in range(cols))
        first_col = any(matrix[r][0] == 0 for r in range(rows))
        
        # Step 2: Use first row and column as markers
        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[r][c] == 0:
                    matrix[r][0] = 0
                    matrix[0][c] = 0
        
        # Step 3: Apply markers to inner matrix
        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0
        
        # Step 4: Zero out first row/col if needed
        if first_row:
            for c in range(cols):
                matrix[0][c] = 0
        
        if first_col:
            for r in range(rows):
                matrix[r][0] = 0
