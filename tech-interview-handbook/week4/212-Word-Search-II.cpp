#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class TrieNode {
   public:
    TrieNode() : isEnd(false), word(nullptr) {}
    unordered_map<char, unique_ptr<TrieNode>> children;
    bool isEnd;
    string const* word;
};
class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        // build a trie of words
        for (auto& word : words) {
            addWord(word);
        }
        // dfs the board
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        auto helper = [&](int a, int b, TrieNode* node) {
            auto dfs = [&](int a, int b, TrieNode* node, auto& dfs_ref) {
                if (a < 0 || a >= board.size()) {
                    return;
                }
                if (b < 0 || b >= board[0].size()) {
                    return;
                }
                if (visited[a][b]) {
                    return;
                }
                if (node->children.count(board[a][b])) {
                    TrieNode* next = node->children[board[a][b]].get();
                    if (next->isEnd) {
                        next->isEnd = false;
                        result.push_back(*(next->word));
                        // return; // DO NOT RETURN!! Even if a word end is found, it it still possible to find another end if we keep searching.
                    }
                    visited[a][b] = true;
                    dfs_ref(a + 1, b, next, dfs_ref);
                    dfs_ref(a - 1, b, next, dfs_ref);
                    dfs_ref(a, b + 1, next, dfs_ref);
                    dfs_ref(a, b - 1, next, dfs_ref);
                    visited[a][b] = false;
                }
            };
            return dfs(a, b, node, dfs);
        };

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                // i, j, TreeNode*
                helper(i, j, &root);
            }
        }

        return result;
    }

   private:
    void addWord(string const& word) {
        auto* cur = &root;
        for (char c : word) {
            if (cur->children.count(c) == 0) {
                cur->children[c].reset(new TrieNode());
            }
            cur = cur->children[c].get();
        }
        cur->isEnd = true;
        cur->word = &word;
    }
    TrieNode root;
};