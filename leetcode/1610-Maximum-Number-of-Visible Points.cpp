#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const double PI = acos(-1);
class Solution {
   public:
    double get_angle(int x_diff, int y_diff) {
        double tmp = atan2(y_diff, x_diff) * 180 / PI;
        if (tmp < 0) {
            return tmp + 360;
        }
        return tmp;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int i, j, n = points.size(), common = 0;
        vector<double> angles;
        for (i = 0; i < n; i++) {
            int x = points[i][0] - location[0];
            int y = points[i][1] - location[1];
            if (x == 0 && y == 0) {
                common++;
            } else {
                double A = get_angle(x, y);
                angles.push_back(A);
            }
        }

        sort(angles.begin(), angles.end());
        vector<double> twoRounds = angles;
        twoRounds.insert(twoRounds.end(), angles.begin(), angles.end());
        for (i = angles.size(); i < twoRounds.size(); i++)
            twoRounds[i] += 360;
        int ret = 0;
        for (i = 0, j = 0; i < twoRounds.size(); i++) {
            while (twoRounds[i] - twoRounds[j] > angle) {
                j++;
            }
            ret = max(ret, i - j + 1);
        }
        return ret + common;
    }
};
