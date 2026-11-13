#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    ListNode* head;
    ListNode* tail;
    int sz;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), sz(0) {}

    void push_back(int val) {
        ListNode* node = new ListNode(val);
        if (!head) { head = tail = node; }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        sz++;
    }

    void push_front(int val) {
        ListNode* node = new ListNode(val);
        if (!head) { head = tail = node; }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        sz++;
    }

    void print() {
        ListNode* cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    int size(){
        return sz;
    }
};