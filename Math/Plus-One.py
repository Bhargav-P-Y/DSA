class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        end = len(digits) -1
        carry = 1 # Start with +1

        for idx in range(end, -1, -1):
            digits[idx] += carry

            carry = digits[idx] //10
            digits[idx] %= 10
        
        if carry:
            digits.insert(0, 1)
        
        return digits

            
            
        
