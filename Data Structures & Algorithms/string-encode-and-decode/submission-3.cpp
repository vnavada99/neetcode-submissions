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
        //cout<< s <<"\n";
        vector<string> lRes;
        //cout<< s.substr(8,10)<< "\n";
        while(i < s.size()-1)
        {
            int j = i;
            while(s[i] != '*')
            {
                i++;
            }
            //cout<< j<< " " << i << "\n";
            int count = std::stoi(s.substr(j, i));
            //cout<< count<< " " << s.substr(i+1, i+count-1)<< "\n";
            lRes.emplace_back(s.substr(i+1, count));
            i = count+i+1;
        }
        
        return lRes;
    }
};
