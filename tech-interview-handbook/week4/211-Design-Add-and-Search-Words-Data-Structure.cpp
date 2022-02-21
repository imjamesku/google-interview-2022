#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct TrieNode {
    char c;
    bool isEnd;
    unordered_map<char, TrieNode *> children;
    TrieNode(char _c, bool _isEnd) : c(_c), isEnd(_isEnd) {}
    TrieNode() : isEnd(false) {}
};
// trie
// class WordDictionary {
//    public:
//     WordDictionary() {
//     }

//     void addWord(string word) {
//         TrieNode *cur = &root;
//         for (char c : word) {
//             if (cur->children.find(c) == cur->children.end()) {
//                 cur->children[c] = new TrieNode{c, false};
//             }
//             cur = cur->children[c];
//         }
//         cur->isEnd = true;
//     }

//     bool search(string word) {
//         // function<bool(size_t, TrieNode *)> searchNode = [&](size_t wordIdx, TrieNode *node) -> bool {
//         //     TrieNode *cur = &root;
//         //     for (size_t i = wordIdx; i < word.size(); i++) {
//         //         if (word[i] == '.') {
//         //             for (auto [key, value] : cur->children) {
//         //                 if (searchNode(i + 1, value)) {
//         //                     return true;
//         //                 }
//         //             }
//         //             return false;
//         //         } else {
//         //             if (cur->children.find(word[i]) != cur->children.end()) {
//         //                 cur = cur->children[i];
//         //             } else {
//         //                 return false;
//         //             }
//         //         }
//         //     }
//         //     return cur->isEnd;
//         // };
//         return searchNode(word.c_str(), &root);
//     }

//    private:
//     TrieNode root;
//     bool searchNode(char const *word, TrieNode *node) {
//         TrieNode *cur = node;
//         for (size_t i = 0; i < word[i] != '\0'; i++) {
//             if (word[i] == '.') {
//                 for (auto [key, value] : cur->children) {
//                     if (searchNode(word + 1, value)) {
//                         return true;
//                     }
//                 }
//                 return false;
//             } else {
//                 if (cur->children.find(word[i]) != cur->children.end()) {
//                     cur = cur->children[word[i]];
//                 } else {
//                     return false;
//                 }
//             }
//         }
//         return cur->isEnd;
//     }
// };
// map solution
class WordDictionary {
   public:
    WordDictionary() {
    }

    void addWord(string word) {
        if (wordsByLength.find(word.size()) == wordsByLength.end()) {
            wordsByLength[word.size()] = unordered_set<string>();
        }
        auto &words = wordsByLength[word.size()];
        if (words.find(word) == words.end()) {
            words.insert(word);
        }
    }

    bool search(string pattern) {
        if (wordsByLength.find(pattern.size()) == wordsByLength.end()) {
            return false;
        }
        auto &words = wordsByLength[pattern.size()];
        if (words.count(pattern)) {
            return true;
        }
        for (string const &word : words) {
            if (isMatch(word, pattern)) {
                return true;
            }
        }
        return false;
    }

   private:
    bool isMatch(string const &word, string const &pattern) {
        for (int i = 0; i < word.size(); i++) {
            if (pattern[i] != '.' && pattern[i] != word[i]) {
                return false;
            }
        }
        return true;
    }
    unordered_map<size_t, unordered_set<string>> wordsByLength;
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main(void) {
    WordDictionary d;
    d.addWord("bad");
    cout << (d.search("bad") ? "found" : "not found")
         << "\n";
    return 0;
}