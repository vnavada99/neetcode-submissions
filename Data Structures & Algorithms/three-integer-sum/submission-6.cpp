class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> res =  {};
        for(int i = 0; i< nums.size()-2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = 0 - nums[i];

            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                if(nums[l]+nums[r] < target)
                {
                    l++;
                    continue;
                }
                    
                if(nums[l]+nums[r] > target)
                {
                    r--;
                    continue;
                }
                else
                {
                    vector<int> ltmp = {nums[i], nums[l], nums[r]};
                    res.emplace_back(ltmp);
                    l++;
                    r--;
                    while(l< r && nums[l] == nums[l-1])
                    {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
