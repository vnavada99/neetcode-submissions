class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        
        vector<int> prefix(height.size(),0);
        vector<int> suffix(height.size(),0);

        prefix[0] = height[0];
        for(int i = 1; i< height.size(); i++)
        {
            prefix[i] = max(height[i], prefix[i-1]);
        }

        suffix[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2; i>= 0; i--)
        {
            suffix[i] = max(height[i], suffix[i+1]);
        }

        int res = 0;
        for(int i=0; i< height.size();i++)
        {
            res += min(prefix[i],suffix[i])- height[i];
        }
        return res;
    }
};
