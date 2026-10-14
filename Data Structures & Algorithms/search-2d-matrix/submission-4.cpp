class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;
        int mid = 0;
        while(l<=r)
        {
            mid = l+ (r-l)/2;
            if(matrix[mid][0] == target)
                return true;

            if(matrix[mid][0] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1; 
            }
 
        }

        if (r < 0)
            return false; 
        mid = r;
        l = 0;
        r = matrix[mid].size()-1;

        while(l<=r)
        {
            int mid1 = l+ (r-l)/2;
            if(matrix[mid][mid1] == target)
                return true;

            if(matrix[mid][mid1] > target)
            {
                r = mid1 - 1;
            }
            else
            {
                l = mid1 + 1; 
            }
        }

        return false;
    }
};
