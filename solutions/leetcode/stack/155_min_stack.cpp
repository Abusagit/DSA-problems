#include <stack>


class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> min_stack;
    
    MinStack() {
    }
    
    void push(int val) {
        if (this->stack.empty()){
            this->min_stack.push(val);
            this->stack.push(val);
        } else {
            this->stack.push(val);
            if (val < this->min_stack.top()){
                this->min_stack.push(val);
            } else {
                this->min_stack.push(this->min_stack.top());
            }
        }
    }
    
    void pop() {
        this->stack.pop();
        this->min_stack.pop();
        
    }
    
    int top() {
        return this->stack.top();
    }
    
    int getMin() {
        return this->min_stack.top();
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