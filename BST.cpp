#include "BST.h"

Node::Node(int v) : value(v), left(nullptr), right(nullptr) {}
Node::~Node() {}

int Node::getValue(){ return value; }
Node* Node::getLeft(){ return left; }
Node* Node::getRight(){ return right; }
void Node::setValue(int v){ value = v; }
void Node::setLeft(Node* l){ left = l; }
void Node::setRight(Node* r){ right = r; }

void Node::print() {
    if (left) left->print();
    cout << value << " ";
    if (right) right->print();
}

BST::BST() : root(nullptr) {}
BST::BST(int value) { root = new Node(value); }

void BST::destroy(Node* node) {
    if (!node) return;
    destroy(node->getLeft());
    destroy(node->getRight());
    delete node;
}

BST::~BST() { destroy(root); }

void BST::insert(int value) {
    if (root == nullptr) { root = new Node(value); return; }
    Node* current = root;
    while (true) {
        if (value > current->getValue()) {
            if (current->getRight() == nullptr) { current->setRight(new Node(value)); return; }
            current = current->getRight();
        }
        else if (value < current->getValue()) {
            if (current->getLeft() == nullptr) { current->setLeft(new Node(value)); return; }
            current = current->getLeft();
        }
        else return; // Дубликаты не добавляем
    }
}

bool BST::contains(int value){
    Node* current = root;
    while (current != nullptr) {
        if (value > current->getValue()) current = current->getRight();
        else if (value < current->getValue()) current = current->getLeft();
        else return true;
    }
    return false;
}

void BST::remove(int value) {
    Node* parent = nullptr;
    Node* current = root;
    while (current != nullptr && current->getValue() != value) {
        parent = current;
        if (value < current->getValue()) current = current->getLeft();
        else current = current->getRight();
    }
    if (current == nullptr) return;
    if (current->getLeft() == nullptr || current->getRight() == nullptr) {
        Node* child = current->getLeft() ? current->getLeft() : current->getRight();
        if (parent == nullptr) root = child;
        else if (parent->getLeft() == current) parent->setLeft(child);
        else parent->setRight(child);
        delete current;
        return;
    }
    Node* minParent = current;
    Node* minNode = current->getRight();
    while (minNode->getLeft() != nullptr) {
        minParent = minNode;
        minNode = minNode->getLeft();
    }
    current->setValue(minNode->getValue());
    if (minParent->getLeft() == minNode) minParent->setLeft(minNode->getRight());
    else minParent->setRight(minNode->getRight());
    delete minNode;
}

void BST::print(){
    if (root) root->print();
    cout << endl;
}

bool BST::isEmpty(){ return root == nullptr; }
