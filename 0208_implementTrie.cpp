#include <string>
using namespace std;
class TrieNode {
private:
    TrieNode* child[26];
    bool isEnd;

public:
    TrieNode() {
        for (auto& c : child) {
            c = nullptr;
        }
        isEnd = false;
    }
    bool contains(char c) { return child[c - 'a']; }
    void insert(char c) { child[c - 'a'] = new TrieNode(); }
    TrieNode* getChild(char c) { return child[c - 'a']; }
    void setIsEnd(bool isEnd) { this->isEnd = isEnd; }
    bool getIsEnd() { return isEnd; }
};
class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char& c : word) {
            if (!curr->contains(c)) {
                curr->insert(c);
            }
            curr = curr->getChild(c);
        }
        curr->setIsEnd(true);
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char& c : word) {
            if (!curr->contains(c)) {
                return false;
            }
            curr = curr->getChild(c);
        }
        return curr->getIsEnd();
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char& c : prefix) {
            if (!curr->contains(c)) {
                return false;
            }
            curr = curr->getChild(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */