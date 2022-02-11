#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(target - nums[i]) == 1) {
                vector ret{indices[target - nums[i]], i};
                return ret;
            }
            indices[nums[i]] = i;
        }
        vector ret{-1, -1};
        return ret;
    }
};