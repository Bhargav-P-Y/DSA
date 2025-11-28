# Sort the array
# Fix left, and adjust middle & right
# You only need to move one of the pointers
# After you found the sum = 0
# Because then it will go back to either
# sum > 0 or sum < 0 condition
# Find a triplet, then skip over duplicates
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        nums.sort()
       
        for l in range(n-2):
            if l>0 and nums[l] == nums[l-1]:
                continue
            m = l+1
            r = n-1

            while m<r:
                total = nums[l] + nums[m] + nums[r]

                if total > 0:
                    r-=1
                elif total < 0:
                    m+=1
                else:
                    res.append([nums[l], nums[m], nums[r]])
                    while m<r and nums[m] == nums[m+1]:
                        m+=1
                    while m<r and nums[r] == nums[r-1]:
                        r-=1
                    m+=1
                    r-=1
        return res


        
