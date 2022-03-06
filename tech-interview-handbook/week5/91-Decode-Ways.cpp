#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    const string all = "1234567890";
    const string zeroToSix = "0123456";
    const string oneToNine = "123456789";
    const string oneToSix = "123456";
    int numDecodings(string s) {
        vector<int> table(s.size() + 1, 0);
        table[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            if (oneToNine.find(s[i]) != string::npos) {
                table[i + 1] += table[i];
            }
            // cout << "456\n";
            if (i >= 1 && isValidTwoDigits(s.substr(i - 1, 2))) {
                table[i + 1] += table[i - 1];
            }
        }
        return table[s.size()];
    }

   private:
    bool isValidTwoDigits(const string& digits) {
        if (digits[0] == '1' && all.find(digits[1]) != string::npos) {
            return true;
        }
        if (digits[0] == '2' && zeroToSix.find(digits[1]) != string::npos) {
            return true;
        }
        return false;
    }
};