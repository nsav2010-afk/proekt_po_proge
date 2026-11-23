#pragma once
#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node *left, *right;
public:
    Node(int v);
    ~Node();
    int getValue();
    Node* getLeft();
    Node* getRight();
    void setValue(int v);
    void setLeft(Node* l);
    void setRight(Node* r);
    void print();
};

class BST {
private:
    Node *root;
    void destroy(Node* node);
public:
    BST();
    BST(int value);
    ~BST();
    void insert(int value);
    bool contains(int value);
    void remove(int value);
    void print();
    bool isEmpty();
    int siz(Node* node);
};