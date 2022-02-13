#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> indices;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            if (indices.count(key) == 0) {
                vector<string> newGroup;
                res.push_back(newGroup);
                indices[key] = res.size() - 1;
            }
            res[indices[key]].push_back(str);
        }
        return res;
    }
};