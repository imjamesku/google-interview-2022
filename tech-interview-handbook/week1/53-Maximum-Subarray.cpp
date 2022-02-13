#include <vector>

using namespace std;
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0, maxSum = INT_MIN;
        for (const int n : nums) {
            currentSum += n;
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};