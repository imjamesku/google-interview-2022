#include <vector>
using namespace std;
// fist attempt 17m31s45
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int remainingJumps = 1;
        int i = 0;
        while (i < nums.size() && remainingJumps > 0) {
            remainingJumps--;
            remainingJumps = max(remainingJumps, nums[i]);
            if (remainingJumps > 0) {
                i++;
            }
        }
        return i >= nums.size() - 1;
    }
};