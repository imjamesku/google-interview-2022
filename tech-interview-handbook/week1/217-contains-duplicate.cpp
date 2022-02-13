// https://leetcode.com/problems/contains-duplicate/
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (const int n : nums) {
            if (s.count(n) == 1) {
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};