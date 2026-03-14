class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        '''
        Assume 1st word is answer, trim it if necessary
        Alternate approach, check vertically
        The ith character for every word upto minlen of all words
        '''

        pref, n = strs[0], len(strs)

        for word in strs:
            minlen = min(len(pref), len(word))
            pref = pref[:minlen]

            for i in range(minlen):
                if pref[i] != word[i]:
                    pref = pref[:i]
                    break
        
        return pref
