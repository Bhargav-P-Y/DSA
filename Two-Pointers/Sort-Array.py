 '''
  Break down the large problem of sorting the entire array 
  into 2 halves
  Keep splitting until we only have a single element
  Then compare and merge from the bottom-up

  Use mid & mid+1
  not mid -1 as l== mid & doing mid -1 might lead to -1 index
  '''

class Solution:
    def merge(self, l, mid, r, nums):
        left = nums[l:mid]
        right = nums[mid:r+1]

        lp, rp = 0, 0
        # Not 0! the current left portion
        cur = l

        # Compare and insert the smaller element
        while lp< len(left) and rp < len(right):
            # If there was an inversion
            if left[lp] > right[rp]:
                nums[cur] = right[rp]
                rp+=1
            else:
                nums[cur] = left[lp]
                lp+=1
            cur +=1
        
        while lp < len(left):
            nums[cur] = left[lp]
            cur+=1
            lp+=1

        while rp < len(right):
            nums[cur] = right[rp]
            cur +=1
            rp +=1
        

    def mergeSort(self, l, r, nums):
        if l < r:
            mid = l + (r-l)//2
            self.mergeSort(l, mid, nums)
            self.mergeSort(mid+1, r, nums)
            self.merge(l, mid, r, nums)
        return
        

    def sortArray(self, nums: List[int]) -> List[int]:
        l, r = 0, len(nums)-1
        self.mergeSort(l, r, nums)
        return nums
       
        
