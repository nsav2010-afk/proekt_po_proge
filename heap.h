#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Heap {
private:
    vector<int> data;
    void siftDown(int i);
    void siftUp(int i);
public:
    Heap() = default;
    ~Heap() = default;

    void push(int val);
    int pop();
    int top() const;
    bool empty() const;
    int getSize() const;
};