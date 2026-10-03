class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numVsIndex;

        for(int i = 0; i < nums.size(); i++)
        {
            numVsIndex[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int find = target - nums[i];
            if(numVsIndex.find(find) != numVsIndex.end() && numVsIndex.at(find) > i)
            {
                return {i, numVsIndex.at(find)};
            }
        }
        return {};
    }
};
