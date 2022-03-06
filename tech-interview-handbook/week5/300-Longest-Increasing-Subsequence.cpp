#include <stdlib.h>

#include <algorithm>
#include <vector>
using namespace std;

// first attempt
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        // endIdx, len
        int lisEndsAt[2500];
        int maxLen = 1;
        for (int i = 0; i < 2500; i++) {
            lisEndsAt[i] = 1;
        }
        for (int end = 0; end < nums.size(); ++end) {
            for (int last = 0; last < end; ++last) {
                if (nums[last] < nums[end]) {
                    lisEndsAt[end] = max(lisEndsAt[end], lisEndsAt[last] + 1);
                    maxLen = max(maxLen, lisEndsAt[end]);
                }
            }
        }
        // for (int i=0; i<nums.size(); i++) {
        //     cout << lisEndsAt[i] << ",";
        // }
        // cout << "\n";
        return maxLen;
    }
};

class Solution2 {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> minEnding;
        for (int num : nums) {
            if (minEnding.size() == 0) {
                minEnding.push_back(num);
            }
            for (int i = minEnding.size() - 1; i >= 0; --i) {
                if (num > minEnding[i]) {
                    if (i == minEnding.size() - 1) {
                        minEnding.push_back(num);
                        break;
                    }
                    if (num < minEnding[i + 1]) {
                        minEnding[i + 1] = num;
                        break;
                    }
                }
            }
        }
        return minEnding.size();
    }
};

// optimized version
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> minEnding;
        for (int num : nums) {
            int i = findIdx(minEnding, num);
            if (i == minEnding.size() - 1) {
                minEnding.push_back(num);
            } else {
                minEnding[i + 1] = num;
            }
        }
        return minEnding.size();
    }

   private:
    int findIdx(vector<int>& nums, int n) {
        // 0, 1, 3
        // 2
        // n > nums[idx]
        int left = 0, right = nums.size() - 1;
        if (right == -1) {
            return -1;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[left] >= n) {
            return left - 1;
        }
        return left;
    }
};
