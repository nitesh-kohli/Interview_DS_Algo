class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    //we 
    void push(int x) {
        if(!q.empty()){
            int y = q.pop();
            q.push(x);
            q.push(y);
        }
        else
            q.push(x);
    }
    
    int pop() {
        q.pop();
    }
    
    int top() {
        q.top();
    }
    
    bool empty() {
        q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */