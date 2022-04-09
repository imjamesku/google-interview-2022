#include <string>
#include <vector>
using namespace std;
// 10m44s52
class Solution {
   public:
    int findMinDifference(vector<string>& timePoints) {
        // sort
        vector<int> tp;
        for (auto t : timePoints) {
            int hr = stoi(t.substr(0, 2));
            int min = stoi(t.substr(3, 2));
            tp.push_back(hr * 60 + min);
        }
        sort(tp.begin(), tp.end());
        tp.insert(tp.end(), tp.begin(), tp.end());
        for (int i = timePoints.size(); i < tp.size(); i++) {
            tp[i] += 24 * 60;
        }
        int minDiff = 24 * 60;
        for (int i = 1; i < tp.size(); i++) {
            minDiff = min(minDiff, tp[i] - tp[i - 1]);
        }
        return minDiff;
    }
};