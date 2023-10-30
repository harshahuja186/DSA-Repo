class MyQueue {
    stack<int> sa,sb;
public:
    MyQueue() {}
    
    void push(int x) {
        while(!sa.empty()){
            sb.push(sa.top());
            sa.pop();
        }
        sa.push(x);
        while(!sb.empty()){
            sa.push(sb.top());
            sb.pop();
        }
    }
    
    int pop() {
        int top_val = sa.top();
        sa.pop();
        return top_val;
    }
    
    int peek() {
        return sa.top();
    }
    
    bool empty() {
        return sa.size()==0;
    }
};

