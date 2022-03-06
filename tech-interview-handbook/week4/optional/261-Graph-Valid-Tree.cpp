#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// first attempt: 18m
class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // no cycle
        // only 1 edge between nodes
        unordered_map<int, unordered_set<int>> neighbors;
        for (auto edge : edges) {
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }
        unordered_set<int> visited;
        auto findCycle = [&](int node, int from) {
            auto helper = [&](int node, int from, auto& helperRef) {
                visited.insert(node);
                for (int nei : neighbors[node]) {
                    if (visited.count(nei)) {
                        if (from == nei) {
                            // Don't go back
                            continue;
                        } else {
                            // found cycle
                            return true;
                        }
                    }
                    bool foundCycle = helperRef(nei, node, helperRef);
                    if (foundCycle) {
                        return true;
                    }
                }
                return false;
            };
            return helper(node, from, helper);
        };
        int foundCycle = findCycle(0, -1);
        if (foundCycle) {
            return false;
        }
        if (visited.size() != n) {
            return false;
        }
        return true;
    }
};

/**
 * @brief solution 2: Graph theory:
 * if the graph is a tree, it must be fully connected and connot have any cycles,
 * so it must have exactly n-1 edges.
 *
 */

class Solution2 {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        // check if fully connected
        unordered_map<int, unordered_set<int>> neis;
        for (auto& edge : edges) {
            neis[edge[0]].insert(edge[1]);
            neis[edge[1]].insert(edge[0]);
        }
        unordered_set<int> visited;
        auto dfs = [&](int node) {
            auto helper = [&](int node, auto& helperRef) {
                if (visited.count(node)) {
                    return;
                }
                visited.insert(node);
                for (int nei : neis[node]) {
                    helperRef(nei, helperRef);
                }
            };
            return helper(node, helper);
        };
        return visited.size() == n;
    }
};

// iterative approach
class Solution3 {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        // check if fully connected
        unordered_map<int, unordered_set<int>> neis;
        for (auto& edge : edges) {
            neis[edge[0]].insert(edge[1]);
            neis[edge[1]].insert(edge[0]);
        }
        unordered_set<int> visited;
        vector<int> stack{0};
        while (stack.size() > 0) {
            int node = stack.back();
            stack.pop_back();
            if (visited.count(node)) {
                continue;
            }
            visited.insert(node);
            for (int nei : neis[node]) {
                stack.push_back(nei);
            }
        }
        return visited.size() == n;
    }
};