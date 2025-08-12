//Process the string
//Reverse the entire string
//Reverse indiviual words in the string

class Solution {
public:
    void rev(string& s, int left, int right)
    {
        while(left<right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        
    
        int n = s.length();
        if(n == 0) return s;
        int read = 0, write = 0;

        while(read<n)
        {
            //Skip leading spaces
            while(read<n && s[read] == ' ')
                read++;
            
            //String is done
            //THis prevent adding an extra space after the entire string is read
            if(read>=n) break;

            //A word was already read
            //So put a space, after reading all the spaces

            if(write>0)
                s[write++] = ' ';
            
            //Continue adding characters
            while(read<n && s[read] != ' ')
                s[write++] = s[read++];  
        }

        //Resize the string
        s.resize(write);

        //Reverse the entire string
        rev(s, 0, write-1);

        //Reverse individual words
        //DOn't need to use find() repeatedly
        //Traverse the string & check for spaces

        int start = 0;

        for(int end = 0;end<=s.length();end++)
        {
            if(end == s.length() || s[end] == ' ')
            {
                rev(s, start, end-1);
                start = end+1;
            }
        }
        return s;   
    }
};
