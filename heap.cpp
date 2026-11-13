#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node(int v) : value(v){}
};

class Heap {
private:
    vector<Node> data;
    int left(int i) {return 2 * i + 1;}
    int right(int i){ return 2 * i + 2;}
    int parent(int i) {return (i - 1) / 2;}

    void siftDown(int n, int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < n && data[l].value > data[largest].value)
            largest = l;
        if (r < n && data[r].value > data[largest].value)
            largest = r;

        if (largest != i) {
            swap(data[i], data[largest]);
            siftDown(n, largest);
        }
    }

    void siftUp(int i) {
        while (i > 0 && data[parent(i)].value < data[i].value) {
            swap(data[i], data[parent(i)]);
            i = parent(i);
        }
    }

public:

    int size(){return data.size(); }
    bool empty(){return data.empty(); }

    Heap(vector<int>& arr) {
        for (int i = 0; i < (int)arr.size(); ++i) {
            data.emplace_back(arr[i]);
        }
    }

    void push(int value) {
        data.emplace_back(value);
        siftUp(data.size() - 1);
    }

    int pop() {
        int top = data.front().value;
        data.front() = data.back();
        data.pop_back();
        if (!data.empty())
            siftDown(data.size(), 0);
        return top;
    }

    void print(){
        for (int i = 0; i < data.size(); ++i) {
            cout << data[i].value;
            if (i + 1 != data.size()) cout << ' ';
        }
        cout << endl;
    }

};