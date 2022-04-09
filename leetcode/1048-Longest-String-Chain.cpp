#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestStrChain(vector<string>& words) {
        // sort by length
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> chainLen;
        int currentMax = 0;
        // remove 1 char and see if in map
        for (auto& word : words) {
            chainLen[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1, string::npos);
                if (chainLen.count(prev)) {
                    chainLen[word] = max(chainLen[word], 1 + chainLen[prev]);
                }
            }
            currentMax = max(currentMax, chainLen[word]);
        }
        return currentMax;
    }
};