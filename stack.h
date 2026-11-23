#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Stack {
private:
    vector<int> data;
public:
    Stack() = default;
    ~Stack() = default;

    void push(int val);
    int pop();
    int top();
    bool empty();
    int size();
};