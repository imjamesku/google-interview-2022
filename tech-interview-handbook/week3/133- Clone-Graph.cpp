/**
Time: 約13分
錯誤：1. Modified the original nodes instead of the copies. 2. recursive lambda要capture self
 *
 */

#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   public:
    // recursive
    Node* cloneGraph(Node* node) {
        // create copy of nodes
        unordered_map<Node*, Node*> nodeMap;
        function<void(Node*)> copy = [&](Node* node) {
            if (node == nullptr) {
                return;
            }
            if (nodeMap.count(node)) {
                return;
            }
            nodeMap[node] = new Node(node->val);
            for (Node* nei : node->neighbors) {
                copy(nei);
                nodeMap[node]->neighbors.push_back(nodeMap[nei]);
            }
        };
        copy(node);
        return nodeMap[node];
    }
    // stack
    Node* cloneGraph(Node* node) {
        // create copy of nodes
        if (node == nullptr) {
            return node;
        }
        unordered_map<Node*, Node*> nodeMap;
        vector<Node*> stack{node};
        nodeMap[node] = new Node(node->val);
        while (stack.size() > 0) {
            auto cur = stack.back();
            stack.pop_back();
            if (cur == nullptr) {
                continue;
            }
            for (auto nei : cur->neighbors) {
                if (!nodeMap.count(nei)) {
                    nodeMap[nei] = new Node(nei->val);
                    stack.push_back(nei);
                }
                nodeMap[cur]->neighbors.push_back(nodeMap[nei]);
            }
        }
        return nodeMap[node];
    }
};