class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        unordered_set<int> lNums = {};

        for(auto& num: nums)
        {
            if(!lNums.contains(num))
                lNums.insert(num);
        }
        int maxSize = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(lNums.contains(nums[i]-1))
                continue;
            
            int localSize = 1;
            while(lNums.contains(nums[i]+localSize))
            {
                localSize++;
            }
            if(localSize > maxSize) 
                maxSize = localSize;
        }

        return maxSize;
    }
};
