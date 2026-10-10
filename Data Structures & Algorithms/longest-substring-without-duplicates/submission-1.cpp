class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length())
        {
            return 0;
        }
        
        int lmax = 1;
        
        int i = 0;
        int j = 1;
        unordered_set<char> lchar = {s[i]};

        while(j< s.length())
        {
           while(i< j && lchar.contains(s[j]))
            {
                lchar.erase(s[i]);
                i++;
            }
            
            lchar.insert(s[j]);
            lmax = max(lmax, (int)lchar.size());
            j++;
        }

        return lmax;
    }
};
