#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace std;
template <typename TT>

// plain BFS
class Solution {
   public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // state i, j, remaining k
        // visited i, j, k
        // bfs
        deque<tuple<int, int, int, int>> q{{0, 0, k, 0}};
        unordered_set<string> visited{makeState(0, 0, k)};
        while (q.size() > 0) {
            auto [i, j, rk, steps] = q.front();
            if (i == grid.size() - 1 && j == grid[0].size() - 1) {
                return steps;
            }
            q.pop_front();
            auto state = makeState(i, j, rk);
            // if (visited.count(state)) {
            //     continue;
            // }
            for (auto [nextI, nextJ] : vector<tuple<int, int>>{{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}}) {
                if (nextI >= 0 && nextI < grid.size() && nextJ >= 0 && nextJ < grid[0].size()) {
                    int nextK = grid[nextI][nextJ] == 0 ? rk : rk - 1;
                    auto nextState = makeState(nextI, nextJ, nextK);
                    if (nextK >= 0 && visited.count(nextState) == 0) {
                        q.push_back({nextI, nextJ, nextK, steps + 1});
                        visited.insert(nextState);
                    }
                }
            }
        }
        return -1;
    }

   private:
    string makeState(int i, int j, int k) {
        stringstream ss;
        ss << i << "," << j << ","
           << k;
        return ss.str();
    }
};

// A star algorithm

struct Cmp {
    bool operator()(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
        return cost(a) > cost(b);
        // return true;
    }
    int cost(tuple<int, int, int, int> t) {
        auto [i, j, k, steps] = t;
        // steps + grid.size() - i - 1 + grid[0].size - j - 1
        // since grid dimenstions are constants, can be omitted
        return steps - i - j;
    }
};
class Solution2 {
   public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, Cmp> q;
        q.push({0, 0, k, 0});
        unordered_set<string> visited{makeState(0, 0, k)};
        while (q.size() > 0) {
            auto [i, j, rk, steps] = q.top();
            if (i == grid.size() - 1 && j == grid[0].size() - 1) {
                return steps;
            }
            if (rk >= grid.size() - i + grid[0].size() - j - 2) {
                return grid.size() - i + grid[0].size() - j - 2 + steps;
            }
            q.pop();
            auto state = makeState(i, j, rk);
            // if (visited.count(state)) {
            //     continue;
            // }
            for (auto [nextI, nextJ] : vector<tuple<int, int>>{{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}}) {
                if (nextI >= 0 && nextI < grid.size() && nextJ >= 0 && nextJ < grid[0].size()) {
                    int nextK = grid[nextI][nextJ] == 0 ? rk : rk - 1;
                    auto nextState = makeState(nextI, nextJ, nextK);
                    if (nextK >= 0 && visited.count(nextState) == 0) {
                        q.push({nextI, nextJ, nextK, steps + 1});
                        visited.insert(nextState);
                    }
                }
            }
        }
        return -1;
    }

   private:
    string makeState(int i, int j, int k) {
        stringstream ss;
        ss << i << "," << j << ","
           << k;
        return ss.str();
    }
};