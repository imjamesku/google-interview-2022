// https://leetcode.com/problems/validate-binary-search-tree/

#include <functional>
using namespace std;
/**
  Definition for a binary tree node.
  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Beware the input range!!
class Solution {
   public:
    bool isValidBST(TreeNode *root) {
        function<bool(long long int, long long int, TreeNode *)> validate = [&](long long int upper, long long int lower, TreeNode *node) -> bool {
            if (node == nullptr) {
                return true;
            }
            long long int val = node->val;
            if (val > lower && val < upper) {
                return validate(val, lower, node->left) && validate(upper, val, node->right);
            }
            return false;
        };
        return validate(LLONG_MAX, LLONG_MIN, root);
    }
};