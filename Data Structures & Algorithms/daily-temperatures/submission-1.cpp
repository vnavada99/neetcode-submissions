class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> lTempVsIndex = {};
        vector<int> res(temperatures.size(),0);
        for(int i = 0; i< temperatures.size(); i++)
        {
            while(!lTempVsIndex.empty() && 
            temperatures[i] > lTempVsIndex.top().first)
            {
                auto& p = lTempVsIndex.top();
                res[p.second] = i - p.second;
                lTempVsIndex.pop();
            }
            lTempVsIndex.push({temperatures[i], i});
        }
        return res;
    }
};
