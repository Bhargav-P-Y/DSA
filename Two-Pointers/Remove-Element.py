class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        '''
        Order not preserved -> swap
        Order preserved -> read & write pointers
        '''
        l, r = 0, len(nums) -1

        while l <= r:
            if nums[l] == val:
                nums[l], nums[r] = nums[r], nums[l]
                r-=1
            else:
                l+=1
        
        return l

        '''
        class Solution:
            def removeElement(self, nums: List[int], val: int) -> int:
                write = 0
                for read in range(len(nums)):
                    if nums[read] != val:
                        nums[write] = nums[read]
                        write += 1
                return write
        '''
        
