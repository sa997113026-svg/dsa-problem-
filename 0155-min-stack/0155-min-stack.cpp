
class MinStack {
public:
    stack<long long> s;
    long long minvalue;

    MinStack() {
        
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minvalue = val;
        }
        else {
            if (val < minvalue) {
                s.push(2LL * val - minvalue);
                minvalue = val;
            }
            else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        if (s.top() < minvalue) {
            minvalue = 2LL * minvalue - s.top();
        }

        s.pop();
    }

    int top() {
        if (s.top() < minvalue) {
            return minvalue;
        }
        return s.top();
    }

    int getMin() {
        return minvalue;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */