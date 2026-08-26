class MinStack {
public:
    stack<int> s;
    stack<int> minS;

    MinStack() {
    }

    void push(int val) {
        s.push(val);

        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        }
    }

    void pop() {
        if (s.top() == minS.top()) {
            minS.pop();
        }

        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};

// class MinStack {
// public:
//     stack<int> s;
//     MinStack() {
//     }
    
//     void push(int value) {
//         s.push(value);
//     }
    
//     void pop() {
//         s.pop();
//     }
    
//     int top() {
//         return s.top();
//     }
    
//     int getMin() {             //in this approach this is o(n)
//         int mini = INT_MAX;
//         stack<int> temp = s;
//         while (!temp.empty()) {
//             mini = min(mini, temp.top());
//             temp.pop();
//         }
//         return mini;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */