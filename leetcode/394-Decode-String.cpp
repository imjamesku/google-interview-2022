#include <sstream>
#include <string>

// 13:15
using namespace std;
class Solution {
   public:
    string decodeString(string s) {
        int idx = 0;
        return parseStr(s, idx);
    }

   private:
    string parseStr(string& s, int& idx) {
        ostringstream ss;
        while (idx < s.size() && s[idx] != ']') {
            int n = parseNum(s, idx);
            string comp = parseComponent(s, idx);
            for (int i = 0; i < n; ++i) {
                ss << comp;
            }
        }
        return ss.str();
    }
    int parseNum(string& s, int& idx) {
        int n = 0;
        while (s[idx] >= '0' && s[idx] <= '9') {
            n *= 10;
            n += s[idx] - '0';
            idx++;
        }
        if (n == 0) {
            return 1;
        }
        return n;
    }
    string parseComponent(string& s, int& idx) {
        if (s[idx] == '[') {
            idx++;
            string comp = parseStr(s, idx);
            idx++;
            return comp;
        }
        string res{};
        while (s[idx] >= 'a' && s[idx] <= 'z') {
            res += s[idx];
            idx++;
        }
        return res;
    }
};