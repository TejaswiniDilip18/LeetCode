class MinStack {
private:
    stack<int> mystack;
    stack<int> minstack;

public:
    MinStack() {}
    
    void push(int val) {
        mystack.push(val);
        if(minstack.empty() || val <= minstack.top()){
            minstack.push(val);
        }
    }
    
    void pop() {
        if(minstack.top()==mystack.top()){
            minstack.pop();
        }
        mystack.pop();
    }
    
    int top() {
        return mystack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */