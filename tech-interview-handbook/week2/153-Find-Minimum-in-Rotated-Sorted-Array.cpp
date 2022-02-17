// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            } else {
                // nums[left] >= nums[right]
                int mid = (left + right) / 2;
                if (nums[left] == nums[mid]) {
                    // since nums[right] is smaller, go right
                    left = mid + 1;
                }
                if (nums[left] < nums[mid]) {
                    // pivot on right of mid
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left];
    }
};