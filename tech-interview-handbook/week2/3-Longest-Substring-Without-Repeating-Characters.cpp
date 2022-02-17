#include <string>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxLen = 0;
        unordered_set<char> exists;
        for (int end = 0; end < s.size(); end++) {
            if (exists.count(s[end]) != 0) {
                while (s[start] != s[end]) {
                    exists.erase(s[start]);
                    start++;
                }
                start++;
            } else {
                exists.insert(s[end]);
            }
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};