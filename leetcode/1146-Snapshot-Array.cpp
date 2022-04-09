#include <vector>

using namespace std;

// 12 mins. Memory Limit Exceeded
class SnapshotArray {
   public:
    SnapshotArray(int length) {
        this->length = length;
        snaps.push_back(vector<int>(length, 0));
    }

    void set(int index, int val) {
        snaps.back()[index] = val;
    }

    int snap() {
        snaps.push_back(snaps.back());
        return snaps.size() - 2;
    }

    int get(int index, int snap_id) {
        return snaps[snap_id][index];
    }

   private:
    vector<vector<int>> snaps;
    int length;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */