class MinStack {
    stack<int> lstack;
    stack<int> lMinStack;
public:
    MinStack() {
        lstack = {};
        lMinStack = {};
    }
    
    void push(int val) {
        if(lstack.empty())
        {
            lstack.push(val);
            lMinStack.push(val);
            return;
        }
        lstack.push(val);
        lMinStack.top()> val ? lMinStack.push(val) : lMinStack.push(lMinStack.top());
    }
    
    void pop() {
        lstack.pop();
        lMinStack.pop();
    }
    
    int top() {
        return lstack.top();
    }
    
    int getMin() {
        return lMinStack.top();
    }
};
