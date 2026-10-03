class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        std::unordered_map<char, int> MapofFirstString = {};

        for(auto& ch: s)
        {
            if(MapofFirstString.contains(ch))
            {
                MapofFirstString[ch] += 1;
            }
            else
            {
                MapofFirstString[ch] = 1;
            }
        }

        for(auto& ch:t)
        {
            if(MapofFirstString.contains(ch) && MapofFirstString.at(ch) !=0)
            {
                MapofFirstString[ch]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
