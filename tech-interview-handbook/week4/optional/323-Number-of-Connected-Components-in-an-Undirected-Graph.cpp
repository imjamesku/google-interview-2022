#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // build neis: O(E)
        unordered_map<int, unordered_set<int>> neis;
        for (auto& edge : edges) {
            neis[edge[0]].insert(edge[1]);
            neis[edge[1]].insert(edge[0]);
        }
        // dfs and count O(V)
        unordered_set<int> visited;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited.count(i)) {
                continue;
            }
            count++;
            vector<int> stack{i};
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
        }
        return count;
    }
};

// DSU solution

class DSU {
   public:
    DSU(int n) : rank(n, 0), unionSets_(n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    };
    const int& unionSets() { return unionSets_; }
    int findRoot(int x) {
        if (parent[x] == x) {
            return x;
        }
        return findRoot(parent[x]);
    }
    void connect(int x, int y) {
        int rootx = findRoot(x);
        int rooty = findRoot(y);
        if (rootx == rooty) {
            return;
        }
        --unionSets_;
        if (rank[rootx] > rank[rooty]) {
            parent[rooty] = rootx;
        } else if (rank[rooty] > rank[rootx]) {
            parent[rootx] = parent[rooty];
        } else {
            parent[rooty] = rootx;
            ++rank[rootx];
        }
    }

   private:
    vector<int> rank;
    vector<int> parent;
    int unionSets_;
};

class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (const auto& edge : edges) {
            dsu.connect(edge[0], edge[1]);
        }
        return dsu.unionSets();
    }
};