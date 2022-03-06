#include <vector>
using namespace std;

// Think of edge cases first!!!!!!!!!!!!
// nums of length 1
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(rob1(nums, 0, nums.size() - 1), rob1(nums, 1, nums.size()));
    }

   private:
    int rob1(const vector<int>& nums, int start, int end) {
        int odd = 0, even = 0;
        for (int i = start; i < end; ++i) {
            if (i % 2 == 0) {
                even = max(even + nums[i], odd);
            } else {
                odd = max(odd + nums[i], even);
            }
        }
        return max(odd, even);
    }
};