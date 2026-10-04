class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res = {};
        vector<int> pref(nums.size(), 1);
        vector<int> post(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++)
            pref[i] = nums[i-1] * pref[i-1];

        for(int j = nums.size()-2; j >= 0; j--)
            post[j] = nums[j+1] * post[j+1];

        for(int i = 0; i < nums.size(); i++)
            res.emplace_back(pref[i]* post[i]);

        return res;
    }
};
