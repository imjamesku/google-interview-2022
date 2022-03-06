
#include <algorithm>
#include <queue>
using namespace std;

// first attempt: 12:44
class Solution {
   private:
    struct Cmp {
        bool operator()(int a, int b) {
            return b < a;
        }
    };

   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // priority queue with earliest end on top
        priority_queue<int, vector<int>, Cmp> endTimes;
        size_t maxUse = 0;
        for (auto const& interval : intervals) {
            while (endTimes.size() > 0 && interval[0] >= endTimes.top()) {
                endTimes.pop();
            }
            endTimes.push(interval[1]);
            maxUse = max(maxUse, endTimes.size());
        }
        return maxUse;
    }
};

// second solution
class Solution {
   private:
    static constexpr bool const START = true;
    static constexpr bool const END = false;
    struct Cmp {
        bool operator()(tuple<int, bool>& a, tuple<int, bool>& b) {
            auto [aTime, aType] = a;
            auto [bTime, bType] = b;
            if (aTime == bTime) {
                // start -> front
                return aType > bType;
            }
            return bTime < aTime;
        }
    };

   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<tuple<int, bool>, vector<tuple<int, bool>>, Cmp> events;
        for (auto& interval : intervals) {
            events.push({interval[0], START});
            events.push({interval[1], END});
        }
        int usingRooms = 0;
        int mx = 0;
        while (events.size() > 0) {
            auto [time, type] = events.top();
            events.pop();
            if (type == START) {
                // cout << "++\n";
                ++usingRooms;
            } else {
                // cout << "--\n";
                --usingRooms;
            }
            // cout << usingRooms << "\n";
            mx = max(mx, usingRooms);
        }
        return mx;
    }
};