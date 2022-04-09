#include <string>
#include <vector>
using namespace std;

// first attempt 11m05s92
class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (string const& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int n1 = stack.back();
                stack.pop_back();
                int n2 = stack.back();
                stack.pop_back();
                // cout << "op: " << token << "n1: " << n1 << "n2: " << n2 << "\n";
                if (token == "+") {
                    stack.push_back(n2 + n1);
                }
                if (token == "-") {
                    stack.push_back(n2 - n1);
                }
                if (token == "*") {
                    stack.push_back(n2 * n1);
                }
                if (token == "/") {
                    stack.push_back(n2 / n1);
                }
            } else {
                stack.push_back(stoi(token));
            }
        }
        return stack.back();
    }
};