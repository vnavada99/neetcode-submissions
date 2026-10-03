class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto &st: strs)
        {
            res+= to_string(st.size());
            res+= '*';
            res+= st;
            //cout<<res << "\n";
        }   
        return res;
    }

    vector<string> decode(string s) {
        if(s.size()==0)
        {
            return {};
        }
        int i = 0;
        vector<string> lRes;
        while(i < s.size()-1)
        {
            int j = i;
            while(s[i] != '*')
            {
                i++;
            }
            int count = std::stoi(s.substr(j, i-j));
            lRes.emplace_back(s.substr(i+1, count));
            i = count+i+1;
        }
        
        return lRes;
    }
};
