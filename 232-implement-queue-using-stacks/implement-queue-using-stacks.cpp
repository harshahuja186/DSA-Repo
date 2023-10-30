class MyQueue {
    stack<int> s_input,s_output;
public:
    MyQueue() {}
    
    void push(int x) {
        s_input.push(x);
    }
    
    int pop() {
        if(s_output.size()!=0){
            int val = s_output.top();
            s_output.pop();
            return val;
        }else{
            while(!s_input.empty()){
                s_output.push(s_input.top());
                s_input.pop();
            }
        }
        if(s_output.size()==0) return -1;
        int val = s_output.top();
        s_output.pop();
        return val;
    }
    
    int peek() {
        if(s_output.size()!=0){
            return s_output.top();
        }else{
            while(!s_input.empty()){
                s_output.push(s_input.top());
                s_input.pop();
            }
        }
        if(s_output.size()==0) return -1;
        return s_output.top();      
    }
    
    bool empty() {
        return s_input.size()==0 && s_output.size()==0;
    }
};

