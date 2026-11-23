#include "Stack.h"

void Stack::push(int val) {
    data.push_back(val);
}

int Stack::pop() {
    if (empty()) throw out_of_range("empty");
    int val = data.back();
    data.pop_back();
    return val;
}

int Stack::top()  {
    if (empty()) throw out_of_range("empty");
    return data.back();
}

bool Stack::empty() {
    return data.empty();
}

int Stack::size() {
    return data.size();
}
