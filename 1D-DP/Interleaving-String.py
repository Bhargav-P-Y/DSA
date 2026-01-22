'''
Recursion then memoization
'''

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
    
        def recur(i, j, k, last, count_1, count_2, dp):
            # Base case
            if k == len(s3):
                return i == len(s1) and j == len(s2) and abs(count_1-count_2) <= 1
            
            # Return results if already computed
            if dp[i][j] != -1:
                return dp[i][j] == 1
            
            if i<len(s1) and s1[i] == s3[k]:
                new_count_1 = count_1 + (1 if last != 's1' else 0)
                # Propagate the results back up
                # Otherwise it will return False even if a path is found
                if recur(i+1, j, k+1, 's1', new_count_1, count_2):
                    dp[i][j] = 1
                    return True
                
            elif j < len(s2) and s2[j] == s3[k]:
                new_count_2 = count_2 + (1 if last != 's2' else 0)
                if recur(i, j+1, k+1, 's2', count_1, new_count_2):
                    dp[i][j] = 1
                    return True
            
            dp[i][j] = 0
            return False
            
        '''
        2 D dp, 
        dp[i][j] -> -1 not explored
        0 -> failed
        1 -> success
        '''

        dp = [[-1 for _ in range(len(s2)+1)] for _ in range(len(s1)+1)]
        
        return recur(0,0,0,'', 0, 0, dp)
