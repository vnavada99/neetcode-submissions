class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> numVsCount;

        for(auto& num: nums)
        {
            if(numVsCount.contains(num))
            {
                return true;
            }
            else
            {
                numVsCount[num] = 1;
            }
        }
        return false;
    }
};