class Solution {

    string makeKey(string& st)
    {
        vector<int> lAlpha(26, 0);
        
        for(char& ch: st)
        {
            lAlpha[ch - 'a'] += 1;
        }
        string res{};
        for(int& i: lAlpha)
        {
            res =res + ',' + to_string(i);
        }
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mMapOfAnaKeyVsVecStr;

        for(string& st: strs)
        {
            string key = makeKey(st);
            if(mMapOfAnaKeyVsVecStr.contains(key))
            {
                mMapOfAnaKeyVsVecStr.at(key).emplace_back(st);
            }
            else
            {
                mMapOfAnaKeyVsVecStr[key] = {st};
            }
        }
        vector<vector<string>> res;
        for (const auto& [key, value] : mMapOfAnaKeyVsVecStr)
        {
            res.emplace_back(value);
        }
        return res;
    }
};
