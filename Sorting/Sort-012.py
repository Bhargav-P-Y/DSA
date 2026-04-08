'''
Your m pointer is your reference
l for 0's
m for 1's
r for 2's

Real world: Product status, Urgent, Pending, Shipped

We must do m<=r
not m<r

nums = [1, 0] 
will work for m<=r
'''

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Use three pointers
        left, mid & right
        Initally left & mid are both 0
        right is at the end of the array
        if a nums[mid] zero we swap then incremetn both left & mid
        if its a 1 then we only move mid
        if its 2, we swap mid with right and decrement right
        but keep mid as is becaue that old right could be a zero or 1
        """
        l, m, r = 0, 0, len(nums)-1
        while m<=r:
            if nums[m] == 0:
                nums[l], nums[m] = nums[m], nums[l]
                l+=1
                m+=1
            elif nums[m] == 1:
                m+=1
            else:
                nums[m], nums[r] = nums[r], nums[m]
                r-=1

        
