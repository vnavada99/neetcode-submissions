class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> lMapNumVsIndices;

        for(int i = 0; i < numbers.size(); i++)
        {
            lMapNumVsIndices[numbers[i]] = i;
        }

        for(int i =0; i < numbers.size(); i++)
        {
            if(lMapNumVsIndices.contains(target- numbers[i]) && 
            lMapNumVsIndices[target- numbers[i]] != i)
                return {i+1, lMapNumVsIndices[target- numbers[i]]+1};
        }
        return {};
    }
};
