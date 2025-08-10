// Check for non-alphanumeric characters
// Shrink the interval

class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.length();
        if(size == 0 || size == 1)
            return true;

        int left = 0;
        int right = size-1;
        while(left<right)
        {
            if(!isalnum(s[left])){
                left++;
                continue;
            }  
            if(!isalnum(s[right])){
                right--;
                continue;
            }
                
            if(tolower(s[left]) != tolower(s[right]) )
                return false;
            else{
                left++;
                right--;
            }
        }
        return true;
        }
    }
};
