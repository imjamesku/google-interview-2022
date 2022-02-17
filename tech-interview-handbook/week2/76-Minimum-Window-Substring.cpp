#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> sCount, tCount;
        for (const char c : t) {
            if (tCount.count(c) != 0) {
                tCount[c]++;
            } else {
                tCount[c] = 1;
            }
        }
        int toInclude = tCount.size();
        int start = 0;
        int minLen = INT_MAX;
        string result = "";
        for (int end = 0; end < s.size(); end++) {
            char curS = s[end];
            if (sCount.count(curS) != 0) {
                sCount[curS]++;
            } else {
                sCount[curS] = 1;
            }
            if (tCount.count(curS) != 0 && tCount[curS] == sCount[curS]) {
                toInclude--;
            }
            while (toInclude == 0) {
                if (end - start + 1 < minLen) {
                    result = s.substr(start, end - start + 1);
                    minLen = end - start + 1;
                }
                if (tCount.count(s[start]) != 0 && sCount[s[start]] == tCount[s[start]]) {
                    toInclude++;
                }
                sCount[s[start]]--;
                start++;
            }
        }
        return result;
    }
};