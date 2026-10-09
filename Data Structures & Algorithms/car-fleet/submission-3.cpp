class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> lPair;
        
        for(int i=0;i<position.size(); i++)
        {
            lPair.emplace_back(position[i], speed[i]);
        }
        sort(lPair.rbegin(), lPair.rend());
      
        double lStack = 0;
        int fleet = 0;
        for(auto& p: lPair)
        {
            double time = (double)(target - p.first) / p.second;
            if (lStack == 0 || lStack < time)
            {
                lStack = time;
                fleet++;
            }
        }

        return fleet;
    }
};
