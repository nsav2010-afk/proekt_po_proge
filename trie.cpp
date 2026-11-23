#include "trie.h"

TrieNode::TrieNode() {
    for (int i = 0; i < 26; i++) children[i] = nullptr;
    isEnd = false;
}
TrieNode::~TrieNode() {}

Trie::Trie() { root = new TrieNode(); }

void Trie::destroy(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < 26; ++i) destroy(node->children[i]);
    delete node;
}

Trie::~Trie() { destroy(root); }

void Trie::insert(string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int idx = c - 'a';
        if (idx < 0 || idx >= 26) continue;
        if (!node->children[idx]) node->children[idx] = new TrieNode();
        node = node->children[idx];
    }
    node->isEnd = true;
}

bool Trie::search(string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int idx = c - 'a';
        if (idx < 0 || idx >= 26 || !node->children[idx]) return false;
        node = node->children[idx];
    }
    return node->isEnd;
}

bool Trie::startsWith(string& prefix){
    TrieNode* node = root;
    for (char c : prefix) {
        int idx = c - 'a';
        if (idx < 0 || idx >= 26 || !node->children[idx]) return false;
        node = node->children[idx];
    }
    return true;
}
