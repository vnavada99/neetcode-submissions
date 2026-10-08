class Solution {
    bool isOperator(const string& st)
    {
        return (st == "+" || st == "-" || st == "*" || st == "/");
    }
    int doOperation(const string& op, int val1, int val2)
    {
        switch(op[0])
        {
            case '+':
                return val1 + val2;
            case '-':
                return val1 - val2;
            case '*':
                return val1 * val2;
            case '/':
                return val1 / val2;     
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0)
        {
            return 0;
        }

        stack<int> lStack;

        for(const auto& t : tokens)
        {
            if(isOperator(t))
            {
                int val1 = lStack.top();
                lStack.pop();
                int val2 = lStack.top();
                lStack.pop();
                
                int res = doOperation(t,val2,val1);
                lStack.push(res);
            }
            else
            {
                lStack.push(stoi(t));
            }
        }
        return lStack.top();
    }
};
