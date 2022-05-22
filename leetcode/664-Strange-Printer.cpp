#include <vector>
using namespace std;
class Solution {
   public:
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
        }

        for (int l = 2; l <= s.size(); ++l) {
            for (int i = 0; i < s.size() - l + 1; ++i) {
                int j = i + l - 1;
                // if (l == 2) {
                //     dp[i][j] = s[i] == s[j] ? 1 : 2;
                //     continue;
                // }
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k <= j - 1; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }

        return dp[0][s.size() - 1];
    }
};