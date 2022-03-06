class Solution {
   public:
    int climbStairs(int n) {
        int table[46] = {0};
        auto calcWays = [&table](int n) {
            auto impl = [&table](int n, auto& selfRef) {
                if (n == 0) {
                    return 1;
                }
                if (n == 1) {
                    return 1;
                }
                if (table[n] != 0) {
                    return table[n];
                }
                table[n] = selfRef(n - 1, selfRef) + selfRef(n - 2, selfRef);
                return table[n];
            };
            return impl(n, impl);
        };
        return calcWays(n);
    }
};

class Solution2 {
   public:
    int climbStairs(int n) {
        int table[46] = {0};
        table[0] = 1;
        table[1] = 1;
        for (int i = 2; i <= n; i++) {
            table[i] = table[i - 1] + table[i - 2];
        }
        return table[n];
    }
};