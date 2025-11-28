"""
This idea of "aggressively skipping" is similar to how we 
skip duplicates in threeSum. 
It’s not mandatory, but it’s a smart tradeoff 
when correctness is preserved and the input size is large.

Because the newarea <= current area, when we move any one pointer
"""

class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights)-1
        h,w, maxArea = 0,0,0

        while l<r:
            h = min(heights[l], heights[r])
            w = r-l

            maxArea = max(maxArea, h*w)
            # Increase height bcz 
            # width is getting reduced
            
            if heights[l] < heights[r]:
                l+=1
            elif heights[r] < heights[l]
                r -=1
            else:
                l+=1
                r -=1

        return maxArea



        
