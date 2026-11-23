#include "Heap.h"

void Heap::siftDown(int i) {
    int size = data.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && data[l] > data[largest]) largest = l;
    if (r < size && data[r] > data[largest]) largest = r;

    if (largest != i) {
        std::swap(data[i], data[largest]);
        siftDown(largest);
    }
}

void Heap::siftUp(int i) {
    while (i > 0 && data[(i - 1) / 2] < data[i]) {
        std::swap(data[i], data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void Heap::push(int val) {
    data.push_back(val);
    siftUp(data.size() - 1);
}

int Heap::pop() {
    if (empty()) throw out_of_range("empty");
    int topVal = data[0];
    data[0] = data.back();
    data.pop_back();
    if (!data.empty()) {
        siftDown(0);
    }
    return topVal;
}

int Heap::top() const {
    if (empty()) throw out_of_range("empty");
    return data[0];
}

bool Heap::empty() const {
    return data.empty();
}

int Heap::getSize() const {
    return data.size();
}
