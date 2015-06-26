class MinStack {
public:
    void push(int x) {
        stk.push(x);
        if(mstk.empty() || mstk.top() >= x){
            mstk.push(x);
        }
    }

    void pop() {
        int top = stk.top();
        stk.pop();
        if(top <= mstk.top()){
            mstk.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mstk.top();
    }
private:
    stack<int> stk;
    stack<int> mstk;
};
