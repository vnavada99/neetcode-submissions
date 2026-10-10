class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() == 0 || prices.size()==1)
             return 0;

        int lmax = 0;

        for(int i = 1; i< prices.size(); i++)
        {
            int j = 0;
            while(j!=i)
            {
                lmax = max(lmax, (prices[i]-prices[j]));
                j++;
            }
            
        }

        return lmax;
    }
};
