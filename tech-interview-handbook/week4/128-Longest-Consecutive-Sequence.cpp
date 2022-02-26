#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// First attempt. Wrong answer
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        // start, end
        // end start
        unordered_map<int, int> startToEnd;
        unordered_map<int, int> endToStart;
        int maxL = 0;
        for (int n : nums) {
            if (startToEnd.find(n) == startToEnd.end()) {
                startToEnd[n] = n;
            }
            if (endToStart.find(n) == endToStart.end()) {
                endToStart[n] = n;
            }
            cout << "n: " << n << "\n";
            if (startToEnd.find(n + 1) != startToEnd.end()) {
                int end = startToEnd[n + 1];
                cout << "start: " << n << ", end: " << end << "\n";
                startToEnd.erase(n + 1);
                startToEnd.at(n) = max(startToEnd.at(n), end);
                endToStart[end] = n;
            }
            if (endToStart.find(n - 1) != endToStart.end()) {
                int start = endToStart[n - 1];
                cout << "end: " << n << ", start: " << start << "\n";
                endToStart.erase(n - 1);
                endToStart.at(n) = min(endToStart.at(n), start);
                startToEnd[start] = n;
            }
            int start = endToStart[n];
            int end = startToEnd[n];
            startToEnd[start] = end;
            endToStart[end] = start;
            maxL = max(maxL, startToEnd[n] - endToStart[n] + 1);
        }
        return maxL;
    }
};

// Solution
class Solution2 {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxStreak = 0;
        for (int n : s) {
            if (s.find(n - 1) == s.end()) {
                int cur = n;
                int streak = 1;
                while (s.count(n + 1)) {
                    streak++;
                    cur++;
                }
                maxStreak = max(maxStreak, streak);
            }
        }
        return maxStreak;
    }
};