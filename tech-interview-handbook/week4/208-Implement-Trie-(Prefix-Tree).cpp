#include <string>
#include <unordered_map>
using std::unordered_map, std::string, std::make_unique, std::unique_ptr;
class TrieNode {
   public:
    TrieNode() : isEnd(false) {}
    unordered_map<char, unique_ptr<TrieNode>> children;
    bool isEnd;
};

class Trie {
   public:
    Trie() {
    }

    void insert(string word) {
        TrieNode *cur = &root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = make_unique<TrieNode>();
            }
            cur = cur->children[c].get();
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode *cur = &root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c].get();
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode *cur = &root;
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c].get();
        }
        return cur->isEnd || cur->children.size() > 0;
    }

   private:
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */