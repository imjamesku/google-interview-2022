#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        function<void(vector<vector<bool>>&, int, int, int)> dfs = [&](vector<vector<bool>>& visited, int i, int j, int lastHeight) {
            if (i < 0 || i >= m) {
                return;
            }
            if (j < 0 || j >= n) {
                return;
            }
            if (visited[i][j] == true) {
                return;
            }
            if (heights[i][j] >= lastHeight) {
                visited[i][j] = true;
                dfs(visited, i + 1, j, heights[i][j]);
                dfs(visited, i - 1, j, heights[i][j]);
                dfs(visited, i, j + 1, heights[i][j]);
                dfs(visited, i, j - 1, heights[i][j]);
            }
        };
        for (int i = 0; i < m; i++) {
            dfs(pacific, i, 0, 0);
            dfs(atlantic, i, n - 1, 0);
        }
        for (int i = 0; i < n; i++) {
            dfs(pacific, 0, i, 0);
            dfs(atlantic, m - 1, i, 0);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] == true && atlantic[i][j] == true) {
                    result.push_back(vector<int>{i, j});
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
    vector<vector<int>> testcase{vector<int>{2, 1}, vector<int>{1, 2}};
    auto result = s.pacificAtlantic(testcase);
    for (auto row : result) {
        for (int item : row) {
            cout << item << ",";
        }
        cout << "\n";
    }
    return 0;
}