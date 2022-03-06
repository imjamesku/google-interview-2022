#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // build a table, where table[i] means whether s[:i] can be broken down
        vector<bool> breakable(s.size() + 1, false);
        breakable[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (const auto& word : wordDict) {
                if (word.size() <= i) {
                    int l = word.size();
                    if (s.substr(i - l, l) == word) {
                        breakable[i] = breakable[i] || breakable[i - l];
                    }
                }
            }
        }
        return breakable[s.size()];
    }
};