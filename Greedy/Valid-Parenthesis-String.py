class Solution:
    def checkValidString(self, s: str) -> bool:
        '''
        Keep a stack
        If the char is ( or * push it
        char is )
        check top if * then pop into star stack
        if top is ( pop is
        if st empty & star empty return false
        otherwise pop * from star stack

        Order matters! Keep track of it via INDICES
        '''
        st = []
        stars = []

        for i in range(len(s)):
            if s[i] == '(':
                st.append(i)
            elif s[i] == '*':
                stars.append(i)
            else:
                if len(st) == 0:
                    if len(stars) == 0:
                        return False
                    else:
                        stars.pop()  
                else:
                    st.pop()
        
        while len(st) > 0 and len(stars) > 0:
            if stars[-1] > st[-1]:
                stars.pop()
                st.pop()
            else:
                return False
        
        return not st

        
            

        
