class MyQueue {
public: 
    stack<int> inp;
    stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if(out.empty()){
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
            int temp = out.top();
            out.pop();
            return temp;
        }
        int temp = out.top();
        out.pop();
        return temp;
    }
    
    int peek() {
        if(out.empty()){
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
            int temp = out.top();
            return temp;
        }
        int temp = out.top();
        return temp;
    }
    
    bool empty() {
        if(inp.empty() && out.empty()){
            return true;
        }
        else    
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */