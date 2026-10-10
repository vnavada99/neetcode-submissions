class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> lMap = {};

        int j = 0;
        int maxRes = 0;
        int maxf = 0;

        for(int i = 0; i< s.size(); i++)
        {
            lMap[s[i]]++;
            maxf = max(maxf, lMap[s[i]]);

            while((i-j+1) - maxf > k)
            {
                lMap[s[j]]--;
                j++;
            }

            maxRes = max(maxRes, i-j+1);
        }
        return maxRes;
    }
};
