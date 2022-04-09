#include <cstdio>
#include <vector>
using namespace std;
class Solution {
   public:
    int minFlips(vector<vector<int>>& mat) {
        /*
        0 0 0 2^9
        0 0 0
        0 0 0

        0 0 1, 3, 4
        0 0

        0
        */
        auto state = mat;
        vector<vector<int>> zeroMatrix(mat.size(), vector<int>(mat[0].size(), 0));
        int minFlips = 1024;
        auto dfs = [&](int i, int j, int flips) {
            auto impl = [&](int i, int j, int flips, auto& self) {
                if (state == zeroMatrix) {
                    minFlips = min(minFlips, flips);
                }
                if (i == mat.size()) {
                    return;
                }
                int nextI = j == mat[0].size() - 1 ? i + 1 : i;
                int nextJ = j == mat[0].size() - 1 ? 0 : j + 1;
                // try not flipping
                self(nextI, nextJ, flips, self);
                // try flipping
                flip(state, i, j);
                if (state == zeroMatrix) {
                    minFlips = min(minFlips, flips + 1);
                }
                self(nextI, nextJ, flips + 1, self);
                flip(state, i, j);
            };
            return impl(i, j, flips, impl);
        };
        dfs(0, 0, 0);
        return minFlips == 1024 ? -1 : minFlips;
    }

   private:
    void printState(vector<vector<int>>& mat) {
        for (auto& row : mat) {
            for (auto n : row) {
                printf("%d, ", n);
            }
            printf("\n");
        }
        printf("\n");
    }
    void flip(vector<vector<int>>& mat, int i, int j) {
        for (int k = 0; k < 3; k++) {
            if (i - 1 + k >= 0 && i - 1 + k < mat.size()) {
                mat[i - 1 + k][j] = !mat[i - 1 + k][j];
            }
            if (j - 1 + k >= 0 && j - 1 + k < mat[0].size()) {
                mat[i][j - 1 + k] = !mat[i][j - 1 + k];
            }
        }
        mat[i][j] = !mat[i][j];
    }
};