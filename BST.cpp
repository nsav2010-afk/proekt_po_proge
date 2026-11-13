#include <iostream>

using namespace std;

class Node {
private:
    int value;
    Node *left, *right;
public:
    Node(int i) {
        value = i;
        left = nullptr;
        right = nullptr;
    }

    int getValue() const {
        return value;
    }

    Node* getLeft() const {
        return left;
    }

    Node* getRight() const {
        return right;
    }

    void setValue(int v){
        value = v;
    }
    void setLeft(Node* l){
        left  = l;
    }
    void setRight(Node* r){
        right = r;
    }

    ~Node() {
    }

    void print() const {
        if (left)  left->print();
        cout << value << " ";
        if (right) right->print();
    }
};

class BST {
private:
    Node *root;
    int size;
public:
    BST() {
        root = nullptr;
    }
    BST(int value) {
        Node *node = new Node(value);
        root = node;
    }
    Node* getRoot() const{
        return root;
    }
    ~BST() {
        delete root;
    }
    int siz(Node* node){
        if (node == nullptr) return 0;
        return 1 + siz(node->getLeft()) + siz(node->getRight());
    }
    int isEmpty(Node *root){
        if(root == nullptr) return true;
        return false;
    }


    void insert(int value) {
        Node* current = root;
        if (root == nullptr) {
            root = new Node(value);
            return;
        }

        while (true) {
            if (value > current->getValue()) {
                if (current->getRight() == nullptr) {
                    current->setRight(new Node(value));
                    return;
                }
                current = current->getRight();
            }
            else if (value < current->getValue()) {
                if (current->getLeft() == nullptr) {
                    current->setLeft(new Node(value));
                    return;
                }
                current = current->getLeft();
            }
            else {
                return;
            }
        }

    }


    bool contains(int value) const {
        Node* current = root;

        while (current != nullptr) {
            if (value > current->getValue()) {
                current = current->getRight();
            }
            else if (value < current->getValue()) {
                current = current->getLeft();
            }
            else {
                return true;
            }
        }
        return false;
    }

    void print() const {
        if (root == nullptr) {
            return;
        }
        root->print();
        cout << endl;
    }


    void remove(int value) {

        Node* parent  = nullptr;
        Node* current = root;

        while (current != nullptr && current->getValue() != value) {
            parent = current;
            if (value < current->getValue()) current = current->getLeft();
            else current = current->getRight();
        }

        if (current == nullptr) {
            return;
        }
        if (current->getLeft() == nullptr || current->getRight() == nullptr) {
            Node* child = nullptr;
            if (current->getLeft() != nullptr) {
                child = current->getLeft();
            } else {
                child = current->getRight();
            }

            if (parent == nullptr) {
                root = child;
            } else if (parent->getLeft() == current) {
                parent->setLeft(child);
            } else {
                parent->setRight(child);
            }

            delete current;
            return;
        }

        Node* minParent = current;
        Node* minNode   = current->getRight();

        while (minNode->getLeft() != nullptr) {
            minParent = minNode;
            minNode   = minNode->getLeft();
        }

        current->setValue(minNode->getValue());

        if (minParent->getLeft() == minNode) {
            minParent->setLeft(minNode->getRight());
        } else {
            minParent->setRight(minNode->getRight());
        }

        delete minNode;
    }

};
