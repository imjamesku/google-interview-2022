#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // top sort
        // parentCount: string->int
        // children: string->string
        vector<string> canMake;
        unordered_map<string, int> parentCount;
        unordered_map<string, unordered_set<string>> children;

        unordered_set<string> supplySet(supplies.begin(), supplies.end());

        // O(NI)
        for (int i = 0; i < recipes.size(); i++) {  // N
            // build parentCount and children
            for (const auto& igd : ingredients[i]) {  // I
                if (supplySet.count(igd) == 0) {
                    children[igd].insert(recipes[i]);
                    parentCount[recipes[i]]++;
                }
            }
            if (parentCount[recipes[i]] == 0) {
                canMake.push_back(recipes[i]);
            }
        }
        // O(N + NI)
        //  top sort
        for (int i = 0; i < canMake.size(); i++) {
            for (auto& child : children[canMake[i]]) {
                parentCount[child]--;
                if (parentCount[child] == 0) {
                    canMake.push_back(child);
                }
            }
        }
        return canMake;
    }
};