//You only need to keep track of maxf
//No need to update it to a smaller value
//Because a longer window, will always have a higher maxf!

//Keep track of maxf, because, you will need the minimum no of replacements

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxlen = 0, n =s.length(), l = 0, maxf = 0;

        for(int r = 0;r<n;r++)
        {
            freq[s[r]]++;
            maxf = max(maxf, freq[s[r]]);

            while(r-l+1-maxf > k)
            {
                freq[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
        
        
        
    }
};
