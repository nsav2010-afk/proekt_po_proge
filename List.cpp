#include "List.h"

ListNode::ListNode(int v) : val(v), prev(nullptr), next(nullptr) {}

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), sz(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLinkedList::push_back(int val) {
    ListNode* node = new ListNode(val);
    if (!head) { head = tail = node; }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    sz++;
}

void DoublyLinkedList::push_front(int val) {
    ListNode* node = new ListNode(val);
    if (!head) { head = tail = node; }
    else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    sz++;
}

int DoublyLinkedList::pop_back() {
    if (empty()) throw out_of_range("empty");
    int val = tail->val;
    ListNode* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    sz--;
    return val;
}

int DoublyLinkedList::pop_front() {
    if (empty()) throw out_of_range("empty");
    int val = head->val;
    ListNode* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    sz--;
    return val;
}

int DoublyLinkedList::size() { return sz; }
bool DoublyLinkedList::empty() { return sz == 0; }
