class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())
        {
            return false;
        }
        unordered_map<char,int> lMap = {};
        for(auto& s: s1)
        {
            lMap[s]++;
        }

        for(int i = 0; i< s2.size(); i++)
        {
            if(!lMap.contains(s2[i]))
            {
                continue;
            }
            unordered_map<char,int> ltmp = lMap;
            int temp = i;
            while(ltmp.contains(s2[i]) && i< s2.size())
            {   
                ltmp[s2[i]]--;
                if(!ltmp[s2[i]])
                {
                    ltmp.erase(s2[i]);
                }
                i++;
            }
            if(!ltmp.size())
                return true;
            else
                i = temp;
        }
        return false;
    }
};
