#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            unordered_map<int, int> umap;
            for (int j = i + 1; j < nums.size(); j++) {
                if (umap.count(target - nums[j]) != 0) {
                    vector<int> newComb{nums[i], target - nums[j], nums[j]};
                    res.push_back(newComb);
                    umap[nums[j]] = j;
                    for (; j < nums.size() - 1 && nums[j + 1] == nums[j]; j++)
                        ;
                } else {
                    umap[nums[j]] = j;
                }
            }
        }
        return res;
    }
};