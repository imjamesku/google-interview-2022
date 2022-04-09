#include <vector>
using namespace std;
class Solution {
   public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> prev(points[0].size(), 0), current, rightMax;
        long long leftMax = 0;
        current = prev;
        rightMax = prev;
        for (int i = 0; i < points.size(); i++) {
            // build rightmax
            rightMax[rightMax.size() - 1] = prev[rightMax.size() - 1];
            for (int j = rightMax.size() - 2; j >= 0; j--) {
                rightMax[j] = max(rightMax[j + 1] - 1, prev[j]);
            }
            leftMax = 0;
            for (int j = 0; j < current.size(); j++) {
                // calc current[j]
                leftMax = max(leftMax - 1, prev[j]);
                current[j] = max(leftMax, rightMax[j]) + points[i][j];
            }
            for (int j = 0; j < prev.size(); j++) {
                prev[j] = current[j];
                current[j] = 0;
            }
        }
        auto it = max_element(prev.begin(), prev.end());
        return *it;
    }
};