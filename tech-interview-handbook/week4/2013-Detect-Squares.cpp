#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
struct key_hash {
    size_t operator()(tuple<int, int> const& t) const {
        return get<0>(t) ^ get<1>(t);
    }
};
class DetectSquares {
   public:
    DetectSquares() {
    }

    void add(vector<int> point) {
        pointCount[make_tuple(point[0], point[1])]++;
    }

    int count(vector<int> point) {
        int total = 0;
        for (auto [pt, cnt] : pointCount) {
            auto [ptx, pty] = pt;
            // printf("[%d, %d]: %d\n", ptx, pty, cnt);
            if (ptx != point[0] && pty != point[1] && abs(ptx - point[0]) == abs(pty - point[1])) {
                // printf("match [%d, %d]: %d\n", ptx, pty, cnt);
                auto p3 = make_tuple(ptx, point[1]);
                auto p4 = make_tuple(point[0], pty);
                if (pointCount.count(p3) && pointCount.count(p4)) {
                    total += cnt * pointCount[p3] * pointCount[p4];
                }
            }
        }
        return total;
    }

   private:
    unordered_map<tuple<int, int>, int, key_hash> pointCount;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */