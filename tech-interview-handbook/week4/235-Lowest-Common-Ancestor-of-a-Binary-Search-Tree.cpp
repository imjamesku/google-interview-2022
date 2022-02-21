#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // first try
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // build parent map
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<tuple<TreeNode*, TreeNode*>> stack{{root, nullptr}};
        while (stack.size() > 0) {
            auto [child, p] = stack.back();
            stack.pop_back();
            if (child == nullptr) {
                continue;
            }
            parent[child] = p;
            stack.push_back({child->left, child});
            stack.push_back({child->right, child});
        }
        // travel up p, save in set
        unordered_set<TreeNode*> pAncestors;
        TreeNode* cur = p;
        while (cur != nullptr) {
            pAncestors.insert(cur);
            cur = parent[cur];
        }
        // travep up q, return first
        cur = q;
        while (cur != nullptr) {
            if (pAncestors.find(cur) != pAncestors.end()) {
                return cur;
            }
            cur = parent[cur];
        }
        return nullptr;
    }
    // Improved version. Utilize binary SEARCH tree properties
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // travel down from root to p. save p's ancestors in set
        unordered_set<TreeNode*> pAncestors;
        TreeNode* cur = root;
        while (cur != nullptr) {
            pAncestors.insert(cur);
            if (p->val > cur->val) {
                cur = cur->right;
            } else if (p->val < cur->val) {
                cur = cur->left;
            } else {
                break;
            }
        }
        // travel down from root to q.
        cur = root;
        TreeNode* lca = nullptr;
        while (cur != nullptr) {
            if (pAncestors.find(cur) != pAncestors.end()) {
                lca = cur;
                if (q->val > cur->val) {
                    cur = cur->right;
                } else if (q->val < cur->val) {
                    cur = cur->left;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        // return last shared ancestor
        return lca;
    }
};