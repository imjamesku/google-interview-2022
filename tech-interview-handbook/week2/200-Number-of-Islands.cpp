#include <vector>
using namespace std;

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (unsigned long i = 0; i < grid.size(); i++) {
            for (unsigned long j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    clearIsland(grid, i, j);
                }
            }
        }
        return count;
    }
    void clearIsland(vector<vector<char>>& grid, int i, int j) {
        function<void(int, int)> visit = [&grid, &visit](int i, int j) {
            if (i < 0 || i >= grid.size()) {
                return;
            }
            if (j < 0 || j >= grid[0].size()) {
                return;
            }
            if (grid[i][j] == '0') {
                return;
            }
            grid[i][j] = '0';
            visit(i + 1, j);
            visit(i - 1, j);
            visit(i, j + 1);
            visit(i, j - 1);
        };
        visit(i, j);
    }
};