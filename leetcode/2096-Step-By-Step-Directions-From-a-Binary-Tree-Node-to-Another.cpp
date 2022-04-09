#include <optional>
#include <string>
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left{nullptr}, right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    string getDirections(TreeNode *root, int startValue, int destValue) {
        // find path from root to start
        string toStart = getPath(root, startValue).value();
        // cout << toStart << "\n";
        // find path from root to dest
        string toDest = getPath(root, destValue).value();
        // cout << toDest << "\n";
        int idx = 0;
        for (idx = 0; idx < toStart.size() && idx < toDest.size(); idx++) {
            if (toStart[idx] != toDest[idx]) {
                break;
            }
        }
        return string(toStart.size() - idx, 'U') + toDest.substr(idx, string::npos);
    }

   private:
    std::optional<string> getPath(TreeNode *root, int dest) {
        if (root == nullptr) {
            return {};
        }
        if (root->val == dest) {
            return "";
        }
        auto left = getPath(root->left, dest);
        if (left) {
            return "L" + left.value();
        }
        auto right = getPath(root->right, dest);
        if (right) {
            return "R" + right.value();
        }
        return {};
    }
};
