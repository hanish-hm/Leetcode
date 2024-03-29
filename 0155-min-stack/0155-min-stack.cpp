class MinStack {
    stack<pair<int, int>> st;
    int mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        mini = min(val,mini);
        st.push({val,mini});
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            if(st.empty()){
                mini = INT_MAX;
            }
            else{
                mini = st.top().second;
            }
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top().first;
        }
        return -1;
    }
    
    int getMin() {
        if(!st.empty()){
            return st.top().second;
        }
        return -1;
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