#pragma once
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int v);
};

class DoublyLinkedList {
private:
    ListNode* head;
    ListNode* tail;
    int sz;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void push_back(int val);
    void push_front(int val);
    int pop_back();
    int pop_front();
    int size();
    bool empty();
};