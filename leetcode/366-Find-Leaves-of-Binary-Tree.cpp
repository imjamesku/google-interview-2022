#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        // topological sort
        //  find first level
        //  build parent map
        unordered_map<TreeNode*, TreeNode*> parentOf;
        vector<TreeNode*> firstLevel;
        buildParentMap(root, nullptr, parentOf, firstLevel);
        // iterate
        vector<TreeNode*> currentLevel = firstLevel;
        vector<vector<int>> history;
        while (currentLevel.size() > 0) {
            vector<int> levelHistory;
            vector<TreeNode*> nextLevel;
            for (auto* node : currentLevel) {
                levelHistory.push_back(node->val);
                auto* parent = parentOf[node];
                if (parent != nullptr) {
                    removeChild(parent, node);
                    if (parent->left == nullptr && parent->right == nullptr) {
                        nextLevel.push_back(parent);
                    }
                }
            }
            history.push_back(levelHistory);
            currentLevel = nextLevel;
        }
        return history;
    }

   private:
    void buildParentMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentOf, vector<TreeNode*>& firstLevel) {
        if (node == nullptr) {
            return;
        }
        parentOf[node] = parent;
        if (node->left == nullptr && node->right == nullptr) {
            firstLevel.push_back(node);
        }
        buildParentMap(node->left, node, parentOf, firstLevel);
        buildParentMap(node->right, node, parentOf, firstLevel);
    }
    void removeChild(TreeNode* parent, TreeNode* child) {
        if (parent->left == child) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
    }
};