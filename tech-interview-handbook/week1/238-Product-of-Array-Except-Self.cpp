// [1, 2, 3, 4]
// [1, 1*1, 1*1*2, 1*2*3]
// [24, 12, 8, 6]

#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int product = 1;
        for (const int n : nums) {
            res.push_back(product);
            product *= n;
        }
        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= product;
            product *= nums[i];
        }
        return res;
    }
};