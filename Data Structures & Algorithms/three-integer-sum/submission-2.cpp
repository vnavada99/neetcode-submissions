class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> lRes = {};

        for(int i=0; i< nums.size()-2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i+1;
            int k = nums.size()-1;
            int target = 0 - nums[i];
            while(j<k)
            {
                if(target < (nums[j] + nums[k]))
                {
                    k--;
                }
                else if(target > (nums[j] + nums[k]))
                {
                    j++;
                }    
                else
                {
                    lRes.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }

        return lRes;
    }
};
