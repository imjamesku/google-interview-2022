#include <map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) {
            return {};
        }
        // count occurences
        map<int, int> occurs;
        for (int n : changed) {
            occurs[n]++;
        }
        vector<int> keys;  // Reason for building the keys as a vector instead of iterating the map directly: DO NOT MODIFY THE MAP WHEN ITERATING IT
        for (auto& [key, value] : occurs) {
            keys.push_back(key);
        }
        vector<int> original;
        for (auto key : keys) {
            auto value = occurs[key];
            if (occurs[2 * key] < occurs[key]) {
                return {};
            }
            for (int i = 0; i < occurs[key]; i++) {
                occurs[key * 2]--;
                original.push_back(key);
            }
        }
        return original;
    }
};