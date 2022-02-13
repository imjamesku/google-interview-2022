#include <string>
#include <unordered_map>
using namespace std;
// 1: count O(n)
class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for (const char c : s) {
            if (umap.count(c) == 1) {
                umap[c]++;
            } else {
                umap[c] = 1;
            }
        }
        for (const char c : t) {
            if (umap.count(c) == 1) {
                if (umap[c] == 1) {
                    umap.erase(c);
                } else {
                    umap[c]--;
                }
            } else {
                return false;
            }
        }
        return umap.empty();
    }
};

// sort: O(nlogn)