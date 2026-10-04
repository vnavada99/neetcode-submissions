class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;

        while(i < j)
        {
            while(i < j  && (numbers[i]+ numbers[j]) > target)
            {
                j--;
            }
            while(i < j && (numbers[i]+ numbers[j]) < target)
            {
                i++;
            }
            if(numbers[i]+ numbers[j] == target)
                return {i+1, j+1};
        }
        return {};
    }
};
