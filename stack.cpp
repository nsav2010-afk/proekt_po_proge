#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> data;
public:
    void push(int val) {
        data.push_back(val);
    }

    void pop() {
        if (data.empty()) return;
        data.pop_back();
    }

    int top() {
        if (data.empty()) return -1;
        return data.back();
    }

    bool empty() {
        return data.empty();
    }
    int size() {
        return data.size();
    }
};