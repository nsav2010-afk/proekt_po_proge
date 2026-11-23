#pragma once
#include <vector>
#include <iostream>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;
    void build(vector<int>& arr, int node, int start, int end);
    void update(int node, int start, int end, int idx, int val);
    int query(int node, int start, int end, int l, int r);
public:
    SegmentTree(vector<int>& arr);
    void update(int idx, int val);
    int query(int l, int r);
};

