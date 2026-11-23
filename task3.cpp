#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    Heap maxHeap;
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        maxHeap.push(w);
    }

    while (maxHeap.getSize() > 1) {
        int y = maxHeap.pop();
        int x = maxHeap.pop();

        if (x != y) {
            maxHeap.push(y - x);
        }
    }

    if (maxHeap.empty()) cout << 0;
    else cout << maxHeap.top();

}
