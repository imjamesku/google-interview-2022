#include <vector>

using namespace std;

// [[1,3],[6,9]], newInterval = [2,5] start: 0, end: 1
// [[1,3],[6,9]], newInterval = [4,5] start: 1, end: 0
// first attempt
// took 30mins
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // find start
        // find end
        int start = -1;
        for (int i = 0; i < intervals.size(); i++) {
            const auto& cur = intervals[i];
            if (cur[1] >= newInterval[0]) {
                start = i;
                break;
            }
        }
        // cout << "start" << start << "\n";
        if (start == -1) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int end = -1;
        for (int i = intervals.size() - 1; i >= 0; i--) {
            const auto& cur = intervals[i];
            if (cur[0] <= newInterval[1]) {
                end = i;
                break;
            }
        }
        // cout << "end" << end << "\n";
        if (end == -1) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        vector<vector<int>> result{intervals.begin(), intervals.begin() + start};
        if (start <= end) {
            result.push_back(vector<int>{min(intervals[start][0], newInterval[0]), max(intervals[end][1], newInterval[1])});
        } else {
            result.push_back(newInterval);
        }
        for (int i = end + 1; i < intervals.size(); i++) {
            result.push_back(intervals[i]);
        }
        return result;
        // determine how to insert
    }
};

// version 2, using flag
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool inserted = false;
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            const auto& cur = intervals[i];
            if (cur[1] < newInterval[0]) {
                result.push_back(cur);
            } else if (cur[0] > newInterval[1]) {
                if (!inserted) {
                    result.push_back(newInterval);
                    inserted = true;
                }
                result.push_back(cur);
            } else {
                newInterval[0] = min(newInterval[0], cur[0]);
                newInterval[1] = max(newInterval[1], cur[1]);
            }
        }
        if (!inserted) {
            result.push_back(newInterval);
        }
        return result;
    }
};

// use insert
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int before = 0;
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            const auto& cur = intervals[i];
            if (cur[1] < newInterval[0]) {
                result.push_back(cur);
                before++;
            } else if (cur[0] > newInterval[1]) {
                result.push_back(cur);
            } else {
                newInterval[0] = min(newInterval[0], cur[0]);
                newInterval[1] = max(newInterval[1], cur[1]);
            }
        }
        result.insert(result.begin() + before, newInterval);
        return result;
    }
};