#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
    int value;
    Node *left, *right;
public:
    Node(int v) {
        value = v;
        left  = nullptr;
        right = nullptr;
    }

    int   getValue() const {
        return value;
    }
    Node* getLeft()  const {
        return left;
    }
    Node* getRight() const {
        return right;
    }

    void setValue(int v) {
        value = v;
    }
    void setLeft(Node* l) {
        left  = l;
    }
    void setRight(Node* r) {
        right = r;
    }

    ~Node(){

    }
};

class Tree {
private:
    Node *root;
    int   n;

    Node* build(vector<int>& a, int tl, int tr) {
        if (tl == tr) {
            return new Node(a[tl]);
        }
        int tm = (tl + tr) / 2;
        Node* l = build(a, tl, tm);
        Node* r = build(a, tm + 1, tr);

        Node* cur = new Node(l->getValue() + r->getValue());

        cur->setLeft(l);
        cur->setRight(r);
        return cur;
    }

    int queryNode(Node* node, int tl, int tr, int l, int r) const {
        if (l > r) return 0;

        if (l == tl && r == tr) {
            return node->getValue();
        }
        int tm = (tl + tr) / 2;
        int sumLeft  = queryNode(node->getLeft(), tl, tm, l, min(r, tm));
        int sumRight = queryNode(node->getRight(), tm + 1, tr, max(l, tm + 1), r);

        return sumLeft + sumRight;
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->getLeft());
        destroy(node->getRight());
        delete node;
    }

public:
    Tree() {
        root = nullptr;
        n = 0;
    }

    void buildTree(vector<int>& a) {
        n = (int)a.size();
        if (n == 0) { root = nullptr; return; }
        root = build(a, 0, n - 1);
    }

    int query(int l, int r) const {
        return queryNode(root, 0, n - 1, l - 1, r - 1);
    }

    ~Tree() {
        delete(root);
    }
};