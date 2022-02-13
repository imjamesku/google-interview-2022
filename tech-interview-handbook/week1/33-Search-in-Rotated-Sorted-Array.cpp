#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            cout << "left:" << left << "right" << right << "\n";
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                if (nums[left] < nums[mid]) {
                    // Pivot on right of mid, meaning all the nums on the left of mid are smaller. Hence target is on the right of mid.
                    left = mid + 1;
                } else {
                    // pivot on left of mid, meaning numbers of the right are sorted, maning nums[right] is the largest number on the right.
                    if (target <= nums[right]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
            } else {
                // target < nums[mid]
                // povit between left and right
                if (nums[left] <= nums[mid]) {
                    // povit on right of mid, meaning all the nums on the left are smallert than nums[mid]
                    if (target < nums[left]) {  // means target is on the right of mid
                        left = mid + 1;
                    } else {
                        // pivot on left
                        right = mid;
                    }
                } else {
                    // pivot on left of mid, meaning all the nums on the right are larger.
                    right = mid;
                }
            }
        }
        cout << "left:" << left << "right" << right;
        return nums[right] == target ? right : -1;
    }
};