class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxHeight = 0;
        int i = 0; 
        int j = heights.size()-1;

        while(i < j)
        {
            int height = (min(heights[i], heights[j]))*(j-i);
            maxHeight = max(maxHeight, height);
            if(heights[i]>= heights[j])
            {    
                j--;
                continue;
            }
            else
            {
                i++;
                continue;
            }
        }
        return maxHeight;
    }
};
