class MinStack {
    
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {
        mainStack = {};
        minStack = {};
    }
    
    void push(int val) {
        if(mainStack.empty())
        {
            mainStack.push(val);
            minStack.push(val);
            return;
        }
        mainStack.push(val);
        val =  min(val, minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
