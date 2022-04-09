#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;
// took about 12 mins
class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // map<c, [(string, i)]>
        unordered_map<char, vector<tuple<string, int>>> next;
        for (auto word : words) {
            next[word[0]].push_back({word, 0});
        }

        int count = 0;
        for (char c : s) {
            auto nextStrs = next[c];
            next[c].clear();
            for (auto [str, idx] : nextStrs) {
                if (idx == str.size() - 1) {
                    count++;
                } else {
                    next[str[idx + 1]].push_back({str, idx + 1});
                }
            }
        }
        return count;
    }
};