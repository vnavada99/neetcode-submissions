class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()> s.size() || t.empty())
        {
            return "";
        }

        unordered_map<char, int> lmap ={}, window = {};

        for(auto& ch: t)
        {
            lmap[ch]++;
        }
        int l = 0;
        int need = (int)lmap.size();
        int have = 0;
        int res = -1;
        int reslen = INT_MAX;

        for(int r = 0; r < (int)s.length(); r++)
        {
            window[s[r]]++;
            if(lmap.contains(s[r]) && window[s[r]] == lmap[s[r]])
            {
                have++;
            }

            while(have == need)
            {
                if(r-l+1 < reslen)
                {
                    reslen = r-l+1;
                    res = l;
                }

                window[s[l]]--;

                if(lmap.contains(s[l]) && window[s[l]] < lmap[s[l]])
                {
                    have--;
                }
                l++;
            }
        }
        cout<< res << " "<< reslen;
        return reslen == INT_MAX? "" : s.substr(res, reslen);
    }
};
