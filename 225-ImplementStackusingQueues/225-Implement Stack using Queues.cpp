class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!empty()) queue.pop_back();
    }

    // Get the top element.
    int top() {
        return *--queue.end();
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue.empty();
    }
private:
    deque<int> queue;
};
