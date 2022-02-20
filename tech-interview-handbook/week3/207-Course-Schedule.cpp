/**
 * Time: 26mins
 *
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    // first try
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // start with one with no parent
        unordered_map<int, unordered_set<int>> parents;
        unordered_map<int, unordered_set<int>> children;
        for (auto& pre : prerequisites) {
            int child = pre[0], parent = pre[1];
            if (parents.count(child)) {
                parents[child].insert(parent);
            } else {
                parents[child] = unordered_set<int>{parent};
            }
            if (children.count(parent)) {
                children[parent].insert(child);
            } else {
                children[parent] = unordered_set<int>{child};
            }
        }
        vector<int> zeroPre;
        for (int i = 0; i < numCourses; i++) {
            if (parents.count(i) == 0) {
                zeroPre.push_back(i);
            }
        }
        for (int i = 0; i < zeroPre.size(); i++) {
            int taking = zeroPre[i];
            if (children.count(taking) == 0) {
                continue;
            }
            for (int child : children[taking]) {
                // remove parent
                if (parents.count(child) == 0) {
                    continue;
                }
                parents[child].erase(taking);
                if (parents[child].size() == 0) {
                    zeroPre.push_back(child);
                }
            }
        }
        return zeroPre.size() == numCourses;
    }
    // optimized
    // parameters V->number of courses, E->number of edges
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // start with one with no parent
        unordered_map<int, int> parentCount;
        unordered_map<int, unordered_set<int>> children;
        // O(E)
        for (auto& pre : prerequisites) {
            int child = pre[0], parent = pre[1];
            if (parentCount.count(child)) {
                parentCount[child]++;
            } else {
                parentCount[child] = 1;
            }
            if (children.count(parent)) {
                children[parent].insert(child);
            } else {
                children[parent] = unordered_set<int>{child};
            }
        }
        vector<int> zeroPre;
        // O(V)
        for (int i = 0; i < numCourses; i++) {
            if (parentCount.count(i) == 0) {
                zeroPre.push_back(i);
            }
        }
        // O(V+E) NOT O(VE) because each edge is visited only ONCE
        for (int i = 0; i < zeroPre.size(); i++) {
            int taking = zeroPre[i];
            if (children.count(taking) == 0) {
                continue;
            }
            for (int child : children[taking]) {
                // remove parent
                parentCount[child]--;
                if (parentCount[child] == 0) {
                    zeroPre.push_back(child);
                }
            }
        }
        return zeroPre.size() == numCourses;
    }
};