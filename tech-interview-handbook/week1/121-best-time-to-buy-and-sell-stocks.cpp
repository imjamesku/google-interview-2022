// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxP = 0;
        for (const int p : prices) {
            maxP = max(maxP, p - minPrice);
            minPrice = min(minPrice, p);
        }
        return maxP;
    }
};