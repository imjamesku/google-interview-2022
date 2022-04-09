#include <string>
using namespace std;
// did not solve it
// 1h12m24s24 after looking at solution
class Solution {
   public:
    bool canTransform(string start, string end) {
        // XL -> LX
        // RX -> XR
        // "LXXLXRLXXL" -> RLRRL
        // "XLLXRXLXLX" -> RLRRL

        // LLRLL
        // LLRLL
        // bfs (str, idx)
        if (start.size() != end.size()) {
            return false;
        }
        string startWithXRemoved = "";
        for (char c : start) {
            if (c != 'X') {
                startWithXRemoved += c;
            }
        }
        string endWithXRemoved = "";
        for (char c : end) {
            if (c != 'X') {
                endWithXRemoved += c;
            }
        }
        if (startWithXRemoved != endWithXRemoved) {
            return false;
        }

        // now we can assume if we remove all X's LR are in the same order.
        // L can only move left and R can only move right.
        int p0{0}, p1{0};
        while (p0 < start.size() && p1 < start.size()) {
            // find the non x position in start & end strings
            // find first non-X characters
            while (p0 < start.size() && start[p0] == 'X') p0++;
            while (p1 < end.size() && end[p1] == 'X') p1++;
            if (p0 == start.size()) {
                return true;
            }
            if (start[p0] == 'L' && p0 < p1) {
                // L can't move right, so return false
                return false;
            }
            if (start[p0] == 'R' && p0 > p1) {
                // R can't move left, so return false;
                return false;
            }
            p0++;
            p1++;
        }
        return true;
    }
};