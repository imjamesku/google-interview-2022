// https://leetcode.com/problems/container-with-most-water/submissions/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int currentMax = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            currentMax = max(currentMax, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return currentMax;
    }
};