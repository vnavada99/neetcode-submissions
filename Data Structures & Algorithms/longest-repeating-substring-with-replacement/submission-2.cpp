class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxf = 0;
        int res = 0;
        unordered_map<char,int> lmap = {};
        for(int r = 0; r< s.size(); r++)
        {
            lmap[s[r]]++;
            maxf = max(maxf, lmap[s[r]]);

            while(r-l+1 - maxf > k)
            {
                lmap[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
