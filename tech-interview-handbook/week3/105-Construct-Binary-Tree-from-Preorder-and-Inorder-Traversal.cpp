/**
 *
 * 花費時間：59分
 * 重點：時間複雜度
 * 因每個recursion建立一個node，時間複雜度為O(n)
 */
#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> inorderIndices;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndices[inorder[i]] = i;
        }
        function<TreeNode *(int, int, int)> buildSubTree = [&](int preHead, int preLen, int inHead) -> TreeNode * {
            if (preLen == 0) {
                return nullptr;
            }
            // take first node in preorder
            TreeNode *root = new TreeNode(preorder[preHead]);
            int rootIdx = inorderIndices[root->val];
            int leftLen = rootIdx - inHead;
            int rightLen = preLen - leftLen - 1;

            // build sub trees
            root->left = buildSubTree(preHead + 1, leftLen, inHead);
            root->right = buildSubTree(preHead + leftLen + 1, rightLen, inHead + leftLen + 1);
            return root;
        };
        return buildSubTree(0, preorder.size(), 0);
    }
};