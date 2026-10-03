class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mMapOfnumsVsCount;
        for(auto& i: nums)
        {
            if(mMapOfnumsVsCount.contains(i))
            {
                mMapOfnumsVsCount[i] += 1;
            }
            else
            {
                mMapOfnumsVsCount[i] = 1;
            }
        }

        vector<vector<int>> lVecBuckets(nums.size()+1);
        
        for (const auto& [key, value] : mMapOfnumsVsCount)
        {
            //cout<< value << " "<< key << "\n";
            lVecBuckets[value-1].emplace_back(key);
        }   
        vector<int> res;
        //cout<< nums.size();
        for(int i = nums.size()-1; i >= 0; i--)
        {
            
            if(lVecBuckets[i].size() == 0)
                continue;

            auto lvec = lVecBuckets[i];
            for(auto& j: lvec)
            {
                res.emplace_back(j);

                if(res.size() == k)
                {
                    return res;
                }
            }
        }
        return {};
    }
};
