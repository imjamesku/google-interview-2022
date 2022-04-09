#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Cmp {
    bool operator()(tuple<int64_t, int64_t, int64_t> a, tuple<int64_t, int64_t, int64_t> b) {
        return get<0>(a) > get<0>(b);
    }
};
class Solution {
   public:
    int racecar(int target) {
        // find min comb
        // dijk. state(steps, pos, speed)

        // 0->1->3->7->7->6->4
        // 0->1->1->1->2->4
        // priority_queue<tuple<int64_t, int64_t, int64_t>,vector<tuple<int64_t, int64_t, int64_t>>,Cmp> pq;
        deque<tuple<int64_t, int64_t, int64_t>> pq;
        pq.push_back({0, 0, 1});
        // unordered_set<string> visited;
        unordered_map<int, unordered_map<int, bool>> visited;
        // visited.insert(makeState(0, 1));
        visited[0][1] = true;

        int bound = 1;
        while (bound < target) {
            bound *= 2;
        }

        while (pq.size() > 0) {
            auto [curSteps, pos, speed] = pq.front();
            // printf("curSteps: %d, pos: %d, speed: %d\n", curSteps, pos, speed);
            pq.pop_front();
            if (pos == target) {
                return curSteps;
            }
            // try A
            // string nextState = makeState(pos + speed, speed * 2);
            if (visited[pos + speed][speed * 2] == false && abs(pos + speed) <= bound) {
                visited[pos + speed][speed * 2] = true;
                pq.push_back({curSteps + 1, pos + speed, speed * 2});
            }
            // try R
            // nextState = makeState(pos, speed > 0 ? -1 : 1);
            int nextSpeed = speed > 0 ? -1 : 1;
            if (visited[pos][nextSpeed] == false) {
                visited[pos][nextSpeed] = true;
                pq.push_back({curSteps + 1, pos, speed > 0 ? -1 : 1});
            }
        }

        // calc num of steps
        return 0;
    }
};