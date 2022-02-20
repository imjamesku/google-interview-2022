#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        // sort
        sort(intervals.begin(), intervals.end());
        auto lastInterval = intervals.begin();
        // compare adjacent 2 and remove the one with larger end
        int removeCount = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if ((*lastInterval)[1] > intervals[i][0]) {
                // remove
                removeCount++;
                if ((*lastInterval)[1] > intervals[i][1]) {
                    // remove last interval
                    lastInterval = intervals.begin() + i;
                }  // else: remove i, keep last interval
            } else {
                // don't remove
                lastInterval = intervals.begin() + i;
            }
        }
        return removeCount;
    }
};