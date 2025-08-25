//THis logic can be used to find no of anagrams in a string

//Use variables to track the frequencies
//No need to traverse repeatedly 26 times!

//DId we get a match, increment
//Did we lose a match, decrement

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int l1 = s1.length(), l2 = s2.length();
        if(l1>l2) return false;
        
        int matches = 0;
        vector<int> freq1(26, 0), freq2(26, 0);

        for(char c: s1) freq1[c-'a']++;

        for(int i =0;i<l1;i++)
            freq2[s2[i]-'a']++;
        
        for(int i = 0;i<26;i++)
        {
            if(freq1[i] == freq2[i])
                matches++;
        }

        if(matches == 26) return true;

        int idx = 0;

        for(int i = l1;i<l2;i++)
        {
            idx = s2[i-l1]-'a';
            freq2[idx]--;

            if(freq1[idx] == freq2[idx])
                matches++;
            else if(freq1[idx] == freq2[idx]+1)
                matches--;
            
            idx = s2[i]-'a';
            freq2[idx]++;
            if(freq1[idx] == freq2[idx])
                matches++;
            else if(freq1[idx] == freq2[idx]-1)
                matches--;
            
            if(matches == 26) return true;
        }
        cout<<matches<<endl;
        return (matches == 26);
    }
};
