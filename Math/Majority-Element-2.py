class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        '''
        There can be atmost 2 elements having freq > n//3 times
        So extend the Boyer Moore voting algo to 2 nos

        How survivors doesn't mean they are the winners
        [1,2,3,1,2,3,1,2,3]
        None of them (1, 2, 3) exceed the threshold -> 9/3
        So there were 2 survivors but 0 winners
        Verify them!

        A num > n//3 will be a survivor, as for it 
        to become zero there need to be 2 eles with freq > 2n/3
        but that contradicts the fact that there are in total n eles
        to cancel the survivor out

        So num > n//3 will be a survivor
        '''
        n = len(nums)
        threshold = n//3

        res = []

        freq1, freq2 = 0, 0
        maj_1, maj_2 = 0, 0

        # Phase 1: Find the candidates
        for num in nums:
            if freq1 == 0:
                maj_1, freq1 = num, 1
            elif freq2 == 0:
                maj_2, freq2 = num, 1
            elif maj_1 == num:
                freq1 +=1
            elif maj_2 == num:
                freq2 +=1
            else:
                freq1 -=1
                freq2 -=1
        
        # Phase 2: Verify Candidates
        c1, c2 = 0, 0
        for num in nums:
            if num == maj_1:
                c1+=1
            elif num == maj_2:
                c2+=1
        
        if c1 > threshold:
            res.append(maj_1)
        if c2 > threshold:
            res.append(maj_2)
        
        return res
