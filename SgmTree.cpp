#include "segmenttree.h"

SegmentTree::SegmentTree(vector<int>& arr) {
    n = arr.size();
    tree.resize(4 * n);
    if (n > 0) build(arr, 1, 0, n - 1);
}

void SegmentTree::build(vector<int>& arr, int node, int start, int end) {
    if (start == end) tree[node] = arr[start];
    else {
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void SegmentTree::update(int node, int start, int end, int idx, int val) {
    if (start == end) tree[node] = val;
    else {
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int SegmentTree::query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

void SegmentTree::update(int idx, int val) {
    if (idx < 0 || idx >= n) throw out_of_range("index out");
    update(1, 0, n - 1, idx, val);
}

int SegmentTree::query(int l, int r) {
    if (l < 0 || r >= n || l > r) throw out_of_range("range out");
    return query(1, 0, n - 1, l, r);
}
