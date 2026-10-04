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
            int eval = nums[i]+1;
            while(lNums.contains(eval))
            {
                localSize++;
                eval++;
            }
            localSize > maxSize ? maxSize = localSize : maxSize = maxSize;
        }

        return maxSize;
    }
};
