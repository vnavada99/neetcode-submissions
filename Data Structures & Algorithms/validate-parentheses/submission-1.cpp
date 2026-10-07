class Solution {
public:
    bool isValid(string s) {
        stack<char> lstack = {};

        for(auto& ch : s)
        {
            if(ch == '{' || ch=='(' || ch=='[')
            {
                lstack.push(ch);
            }
            else
            {
                if(!lstack.size())
                    return false;
                if(!(ch == '}' && lstack.top() == '{' ||
                ch == ')' && lstack.top() == '(' ||
                ch == ']' && lstack.top() == '['))
                {
                    return false;
                }
                lstack.pop();
            }
        }
        return !lstack.size();
    }
};
