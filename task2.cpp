#include <iostream>
#include "Stack.h"

using namespace std;

void sortStack(Stack& s) {
    Stack tempStack;

    while (!s.empty()) {
        int temp = s.pop();
        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.pop());
        }
        tempStack.push(temp);
    }

    while (!tempStack.empty()) {
        s.push(tempStack.pop());
    }
}

int main() {
    Stack s;
    int n;
    cin >> n;
    for(int i = 0; i < n, i++){
        int x;
        cin >> x;
        s.push(x);
    }
    sortStack(s);
    while (!s.empty()) {
        cout << s.pop() << " ";
    }
}
