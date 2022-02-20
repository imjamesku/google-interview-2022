#include <algorithm>
#include <functional>
using namespace std;
/**
 * Definition for a binary tree node.
 */
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
    int maxPathSum(TreeNode *root) {
        int currentMax = INT_MIN;
        function<int(TreeNode *)> pathSum = [&](TreeNode *root) -> int {
            if (root == nullptr) {
                return 0;
            }
            int left = pathSum(root->left);
            int right = pathSum(root->right);
            int maxSum = left + root->val + right;
            if (maxSum > currentMax) {
                currentMax = maxSum;
            }
            return max({left + root->val, right + root->val, 0});
        };
        pathSum(root);
        return currentMax;
    }
};