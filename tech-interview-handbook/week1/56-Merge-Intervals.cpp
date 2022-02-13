#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &int1, vector<int> &int2) { return int1[0] <= int2[0]; });
        vector<vector<int>> res;
        for (vector<int> interval : intervals) {
            if (res.size() == 0 || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else if (res.back()[1] >= interval[0]) {
                res.back()[1] = max(interval[1], res.back()[1]);
            }
        }
        for (auto interval : res) {
            cout << "[" << interval[0] << "," << interval[1] << "],";
        }
        cout << "\n";
        return res;
    }
};

int main(void) {
    Solution s;
    vector<vector<int>> intervals;
    vector<int> interval1{3, 4};
    vector<int> interval2{1, 2};
    vector<int> interval3{1, 3};
    intervals.push_back(interval1);
    intervals.push_back(interval2);
    intervals.push_back(interval3);
    s.merge(intervals);
    return 0;
}