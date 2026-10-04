class Solution {
    bool isValidChar(char ch)
    {
        if(ch >= 'A' && ch<= 'Z' ||
            ch >= 'a' && ch<= 'z' ||
            ch >= '0' && ch<= '9')
        {
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        int i =0;
        int j = s.length()-1;
    
        while(i < j)
        {
            while(i < j && !isValidChar(s[i]))
                i++;

            while(i < j && !isValidChar(s[j]))
                j--;

            if(tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;  
        }   
        return true;
    }
};
