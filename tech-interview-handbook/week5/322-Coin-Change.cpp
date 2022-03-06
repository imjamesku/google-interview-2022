#include <vector>
using namespace std;
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int const MAX = amount + 1;
        vector<int> combs(amount + 1, MAX);
        combs[0] = 0;
        for (size_t i = 1; i <= amount; i++) {
            for (int value : coins) {
                if (value <= i) {
                    combs[i] = min(combs[i], 1 + combs[i - value]);
                }
            }
        }
        return combs[amount] == MAX ? -1 : combs[amount];
    }
};