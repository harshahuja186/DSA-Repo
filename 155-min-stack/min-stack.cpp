class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int num) {
        if(st.empty()) st.push({num,num});
		else st.push({num,min(st.top().second,num)});
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top().first;   
    }
    
    int getMin() {
        if(st.empty()) return -1;
		return st.top().second;
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