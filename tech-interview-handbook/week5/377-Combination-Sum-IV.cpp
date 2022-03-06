#include <vector>
using namespace std;
class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        size_t dp[1001] = {0};
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int n : nums) {
                if (i - n >= 0) {
                    dp[i] += dp[i - n];
                }
            }
        }
        return dp[target];
    }
};

class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<size_t> table(1001, -1);
        table[0] = 1;
        auto dp = [&table, &nums](int n) -> size_t {
            auto impl = [&table, &nums](int n, auto& selfRef) -> size_t {
                if (table[n] != -1) {
                    return table[n];
                }
                int sum = 0;
                for (int num : nums) {
                    if (n - num >= 0) {
                        sum += selfRef(n - num, selfRef);
                    }
                }
                table[n] = sum;
                return sum;
            };
            return impl(n, impl);
        };
        return dp(target);
    }
};
