class MyStack {
private:
    queue<int>q1;
    queue<int>q2;
    int last;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        last = x;
    }
    
    int pop() {
        while(q1.size() > 1){
            last = q1.front();
            q1.pop();
            q2.push(last);
        }
        last = q1.front();
        q1.pop();
        queue<int>tmp = q1;
        q1 = q2;
        q2 = tmp;
        return last ;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
       return q1.empty();
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