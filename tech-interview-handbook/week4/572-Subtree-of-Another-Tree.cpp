
/**
 * Definition for a binary tree node.
 */

#include <string>
#include <unordered_map>
using namespace std;
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
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        return root1->val == root2->val && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    }
    // first try
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        // if root same, check left
        if (subRoot != nullptr && root->val == subRoot->val) {
            if (isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right)) {
                return true;
            }
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    // using hash
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        hash<string> hash;
        unordered_map<TreeNode*, string> hashOfNode;
        function<string(TreeNode*)> buildHash = [&](TreeNode* root) -> string {
            if (root == nullptr) {
                hashOfNode[root] = '#';
            } else {
                hashOfNode[root] = to_string(hash(to_string(root->val) + buildHash(root->left) + buildHash(root->right)));
            }
            return hashOfNode[root];
        };

        buildHash(root);
        buildHash(subRoot);

        function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* root, TreeNode* subRoot) -> bool {
            if (hashOfNode[root] == hashOfNode[subRoot]) {
                return true;
            }
            if (root == nullptr) {
                return false;
            }
            return dfs(root->left, subRoot) || dfs(root->right, subRoot);
        };
        return dfs(root, subRoot);
    }
};