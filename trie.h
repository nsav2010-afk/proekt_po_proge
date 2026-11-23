#pragma once
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode();
    ~TrieNode();
};

class Trie {
private:
    TrieNode* root;
    void destroy(TrieNode* node);
public:
    Trie();
    ~Trie();
    void insert(string& word);
    bool search(string& word);
    bool startsWith(string& prefix);
};