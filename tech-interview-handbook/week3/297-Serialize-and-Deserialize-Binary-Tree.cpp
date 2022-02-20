#include <string>
using namespace std;

/**
 * time taken 54mins
 * 重點：lambda使用共用ｓｔａｒｔ變數來當作start position、process string from head to end
 * time complexityO(n)
 * string.find, string::npos
 * substr
 * stoi, to_string
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "*";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + "," + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout<<data<<"\n";
        int start = 0;
        function<TreeNode*(void)> desSubStr = [&]() -> TreeNode* {
            int dilPos = data.find(",", start);
            if (dilPos == string::npos) {
                // delimiter not found. last node
                int len = data.length() - start;
                string rootStr = data.substr(start, len);
                if (rootStr == "*") {
                    return nullptr;
                }
                int val = stoi(rootStr);
                return new TreeNode(val);
            }
            int len = dilPos - start;
            string rootStr = data.substr(start, len);
            start = dilPos + 1;  // update start
            if (rootStr == "*") {
                return nullptr;
            }
            int val = stoi(rootStr);
            TreeNode* root = new TreeNode(val);
            root->left = desSubStr();
            root->right = desSubStr();
            return root;
        };
        TreeNode* root = desSubStr();
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));